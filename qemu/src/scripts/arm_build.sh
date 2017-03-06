# /bin/bash

TOOLCHAIN_SRC_URL="http://releases.linaro.org/14.05/components/toolchain/binaries/gcc-linaro-arm-linux-gnueabihf-4.9-2014.05_linux.tar.xz"
BUSYBOX_SRC_URL="http://busybox.net/downloads/busybox-1.23.2.tar.bz2"
KERNEL_SRC_URL="https://www.kernel.org/pub/linux/kernel/v3.x/linux-3.18.21.tar.xz"

TOOLCHAIN="toolchain_src"
BUSYBOX="busybox_src"
KERNEL="linux_src"

BUSYBOX_PALTFORM="busybox-arm"
LINUX_PALTFORM="linux-arm-basic"


usage() {
cat <<USAGE

Usage:
    bash $0 <TARGET_PRODUCT> [OPTIONS]

Description:
    Builds Android tree for given TARGET_PRODUCT

OPTIONS:
    -c, --clean_build
        Clean build - build from scratch by removing entire out dir

    -d, --debug
        Enable debugging - captures all commands while doing the build

    -h, --help
        Display this help message

    -i, --image
        Specify image to be build/re-build (bootimg/sysimg/usrimg)

    -j, --jobs
        Specifies the number of jobs to run simultaneously (Default: 8)

    -k, --kernel_defconf
        Specify defconf file to be used for compiling Kernel

    -l, --log_file
        Log file to store build logs (Default: <TARGET_PRODUCT>.log)

    -m, --module
        Module to be build

    -p, --project
        Project to be build

    -s, --setup_ccache
        Set CCACHE for faster incremental builds (true/false - Default: true)

    -u, --update-api
        Update APIs

    -v, --build_variant
        Build variant (Default: userdebug)

USAGE
}

clean_build() {
    TOP=`pwd`
    echo $TOP

    mkdir "$TOOLCHAIN"
    mkdir "$BUSYBOX"
    mkdir "$KERNEL"

    wget -P /tmp/ "$TOOLCHAIN_SRC_URL" && tar xJf "/tmp/`basename $TOOLCHAIN_SRC_URL`" -C "$TOOLCHAIN" --strip-components=1
    wget -P /tmp/ "$BUSYBOX_SRC_URL" && tar xjf "/tmp/`basename $BUSYBOX_SRC_URL`" -C "$BUSYBOX" --strip-components=1
    wget -P /tmp/ "$KERNEL_SRC_URL" && tar xJf "/tmp/`basename $KERNEL_SRC_URL`" -C "$KERNEL" --strip-components=1

    export PATH=${PATH}:${TOP}/${TOOLCHAIN}/bin
    export CC=arm-linux-gnueabihf-gcc


    ## build busybox
    cd $TOP/$BUSYBOX
    mkdir -pv ../obj/$BUSYBOX_PALTFORM
    make mrproper
    make ARCH=arm O=../obj/$BUSYBOX_PALTFORM defconfig
    sed -i 's/.*CONFIG_STATIC.*/CONFIG_STATIC=y/' ../obj/$BUSYBOX_PALTFORM/.config
    sed -i 's/.*CONFIG_INSTALL_NO_USR.*/CONFIG_INSTALL_NO_USR=y/' ../obj/$BUSYBOX_PALTFORM/.config
    sed -i 's/.*CONFIG_FEATURE_PREFER_APPLETS.*/CONFIG_FEATURE_PREFER_APPLETS=y/' ../obj/$BUSYBOX_PALTFORM/.config
    sed -i 's/.*CONFIG_FEATURE_SH_STANDALONE.*/CONFIG_FEATURE_SH_STANDALONE=y/' ../obj/$BUSYBOX_PALTFORM/.config
    make ARCH=arm  clean
    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- O=../obj/$BUSYBOX_PALTFORM -j12 2>&1 | tee  ../busybox_build.log
    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- O=../obj/$BUSYBOX_PALTFORM install

    # initramfs
    mkdir -p $TOP/initramfs/$BUSYBOX_PALTFORM
    cd $TOP/initramfs/$BUSYBOX_PALTFORM
    mkdir -pv {bin,sbin,etc/init.d,proc,sys,dev,lib,usr/{bin,sbin}}
    cp -av $TOP/obj/$BUSYBOX_PALTFORM/_install/* .

    cd dev
    sudo mknod -m 660 null c 1 3
    sudo mknod -m 622 dev/console c 5 1
    sudo mknod -m 622 dev/tty0 c 4 0
    ln -sf null tty2
    ln -sf null tty3
    ln -sf null tty4
    cd ..

    #cp -a $TOP/toolchain_src/arm-linux-gnueabihf/libc/* lib

cat << EOF > etc/init.d/rcS
#!/bin/sh
mount -t proc none /proc
mount -t sysfs none /sys
echo -e "\nBoot took $(cut -d" " -f1 /proc/uptime) seconds\n"
EOF

    chmod 755 etc/init.d/rcS

    find . -print0 \
        | cpio --null -ov --format=newc \
        | gzip -9 > $TOP/obj/initramfs-"$BUSYBOX_PALTFORM".cpio.gz

    # build kernel
    cd $TOP
    mkdir -pv obj/"$LINUX_PALTFORM"
    make ARCH=arm -C $KERNEL O=../obj/"$LINUX_PALTFORM" ARCH=arm mrproper
    make ARCH=arm -C $KERNEL O=../obj/"$LINUX_PALTFORM"  vexpress_defconfig
    sed -i 's/.*CONFIG_EXPERIMENTAL.*/CONFIG_EXPERIMENTAL=y/' obj/$LINUX_PALTFORM/.config
    sed -i 's/.*CONFIG_DEBUG_INFO.*/CONFIG_DEBUG_INFO=y/' obj/$LINUX_PALTFORM/.config
    sed -i 's/.*CONFIG_KGDB.*/CONFIG_KGDB=y/' obj/$LINUX_PALTFORM/.config
    sed -i 's/.*CONFIG_KGDB_LOW_LEVEL_TRAP.*/CONFIG_KGDB_LOW_LEVEL_TRAP=y/' obj/$LINUX_PALTFORM/.config
    sed -i 's/.*CONFIG_FRAME_POINTER.*/CONFIG_FRAME_POINTER=y/' obj/$LINUX_PALTFORM/.config
    sed -i 's/.*CONFIG_MAGIC_SYSRQ.*/CONFIG_MAGIC_SYSRQ=y/' obj/$LINUX_PALTFORM/.config
    sed -i 's/.*CONFIG_8139CP.*/CONFIG_8139CP=y/' obj/$LINUX_PALTFORM/.config
    sed -i 's/.*CONFIG_DEBUG_SET_MODULE_RONX.*/CONFIG_DEBUG_SET_MODULE_RONX=n/' obj/$LINUX_PALTFORM/.config
    sed -i 's/.*CONFIG_DEBUG_RODATA.*/CONFIG_DEBUG_RODATA=n/' obj/$LINUX_PALTFORM/.config
    sed -i 's/.*CONFIG_MODULE_FORCE_LOAD.*/CONFIG_MODULE_FORCE_LOAD=y/' obj/$LINUX_PALTFORM/.config
    sed -i 's/.*CONFIG_MODULE_UNLOAD.*/CONFIG_MODULE_UNLOAD=y/' obj/$LINUX_PALTFORM/.config
    sed -i 's/.*CONFIG_MODULE_FORCE_UNLOAD.*/CONFIG_MODULE_FORCE_UNLOAD=y/' obj/$LINUX_PALTFORM/.config

cat << EOF >> obj/"$LINUX_PALTFORM"/.config
CONFIG_KPROBES_ON_FTRACE=y
CONFIG_UPROBES=y
CONFIG_TRACE_IRQFLAGS=y
CONFIG_TRACER_MAX_TRACE=y
CONFIG_RING_BUFFER_ALLOW_SWAP=y
CONFIG_FTRACE=y
CONFIG_FUNCTION_TRACER=y
CONFIG_FUNCTION_GRAPH_TRACER=y
CONFIG_IRQSOFF_TRACER=y
CONFIG_SCHED_TRACER=y
CONFIG_FTRACE_SYSCALLS=y
CONFIG_TRACER_SNAPSHOT=y
CONFIG_TRACER_SNAPSHOT_PER_CPU_SWAP=y
CONFIG_STACK_TRACER=y
CONFIG_UPROBE_EVENT=y
CONFIG_DYNAMIC_FTRACE=y
CONFIG_DYNAMIC_FTRACE_WITH_REGS=y
CONFIG_FUNCTION_PROFILER=y
CONFIG_FTRACE_MCOUNT_RECORD=y
CONFIG_FTRACE_SELFTEST=y
CONFIG_FTRACE_STARTUP_TEST=y
CONFIG_EVENT_TRACE_TEST_SYSCALLS=y
CONFIG_MMIOTRACE=y
CONFIG_PERCPU_RWSEM=y
EOF

    yes '' | make ARCH=arm -C $KERNEL O=../obj/$LINUX_PALTFORM oldconfig
    make -C $KERNEL O=../obj/$LINUX_PALTFORM clean
    time make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C $KERNEL O=../obj/$LINUX_PALTFORM -j12 2>&1 | tee kernel_build.log
}

qemu() {
    qemu-system-arm -M vexpress-a9 \
    -kernel obj/"$LINUX_PALTFORM"/arch/arm/boot/zImage \
    -initrd obj/initramfs-"$BUSYBOX_PALTFORM".cpio.gz \
    -serial stdio \
    -append "root=/dev/ram rdinit=/sbin/init console=ttyAMA0"
}

gdb() {
    qemu-system-arm -M vexpress-a9 \
    -kernel obj/"$LINUX_PALTFORM"/arch/arm/boot/zImage \
    -initrd obj/initramfs-"$BUSYBOX_PALTFORM".cpio.gz \
    -serial stdio \
    -append "root=/dev/ram rdinit=/sbin/init console=ttyAMA0"
    #-kernel zImage \
    #-initrd rootfs.img \
    #-initrd obj/initramfs-"$BUSYBOX_PALTFORM".cpio.gz \
}

initramfs() {
    TOP=`pwd`
    cd $TOP/initramfs/"$BUSYBOX_PALTFORM"

    #find ./ | cpio -o -H newc | gzip > $TOP/obj/initramfs-$BUSYBOX_PALTFORM.cpio.gz

    find . -print0 \
    | cpio --null -ov --format=newc \
    | gzip -9 > $TOP/obj/initramfs-"$BUSYBOX_PALTFORM".cpio.gz
}

while true; do
    case "$1" in
        -c|--clean_build) clean_build; exit 0;;
        -h|--help) usage; exit 0;;
        -r|--run) qemu; exit 0;;
        -i|--initramfs) initramfs; exit 0;;
        -d|--debug) gdb; exit 0;;
        --) shift; break;;
    esac
    shift
done
