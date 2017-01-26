# 動態庫的鏈接和鏈接選項-L，-rpath-link，-rpath


如何程序在連接時使用了共享庫，就必須在運行的時候能夠找到共享庫的位置。linux的可執行程序在執行的時候默認是先搜索/lib和/usr/lib這兩個目錄，然後按照/etc/ld.so.conf裡面的配置搜索絕對路徑。同時，Linux也提供了環境變量LD_LIBRARY_PATH供用戶選擇使用，用戶可以通過設定它來查找除默認路徑之外的其他路徑，如查找/work/lib路徑,你可以在/etc/rc.d/rc.local或其他系統啟動後即可執行到的腳本添加如下語句：LD_LIBRARY_PATH =/work/lib:$(LD_LIBRARY_PATH)。並且LD_LIBRARY_PATH路徑優先於系統默認路徑之前查找（詳細參考《使用LD_LIBRARY_PATH》）。

不過LD_LIBRARY_PATH的設定作用是全局的，過多的使用可能會影響到其他應用程序的運行，所以多用在調試。（LD_LIBRARY_PATH的缺陷和使用準則，可以參考《Why LD_LIBRARY_PATH is bad》 ）。通常情況下推薦還是使用gcc的-R或-rpath選項來在編譯時就指定庫的查找路徑，並且該庫的路徑信息保存在可執行文件中，運行時它會直接到該路徑查找庫，避免了使用LD_LIBRARY_PATH環境變量查找。

##鏈接選項和路徑
現代連接器在處理動態庫時將鏈接時路徑（Link-time path）和運行時路徑（Run-time path）分開,用戶可以通過-L指定連接時庫的路徑，通過-R（或-rpath）指定程序運行時庫的路徑，大大提高了庫應用的靈活性。比如我們做嵌入式移植時#arm-linux-gcc $(CFLAGS) –o target –L/work/lib/zlib/ -llibz-1.2.3 (work/lib/zlib下是交叉編譯好的zlib庫)，將target編譯好後我們只要把zlib庫拷貝到開發板的系統默認路徑下即可。或者通過-rpath（或-R ）、LD_LIBRARY_PATH指定查找路徑。

鏈接器ld的選項有 -L，-rpath 和 -rpath-link，看了下 man ld，大致是這個意思：

-L: “鏈接”的時候，去找的目錄，也就是所有的 -lFOO 選項裡的庫，都會先從 -L 指定的目錄去找，然後是默認的地方。編譯時的-L選項並不影響環境變量LD_LIBRARY_PATH，-L只是指定了程序編譯連接時庫的路徑，並不影響程序執行時庫的路徑，系統還是會到默認路徑下查找該程序所需要的庫，如果找不到，還是會報錯，類似cannot open shared object file。

-rpath-link：這個也是用於“鏈接”的時候的，例如你顯示指定的需要 FOO.so，但是 FOO.so 本身是需要 BAR.so 的，後者你並沒有指定，而是 FOO.so 引用到它，這個時候，會先從 -rpath-link 給的路徑裡找。

-rpath: “運行”的時候，去找的目錄。運行的時候，要找 .so 文件，會從這個選項裡指定的地方去找。對於交叉編譯，交叉編譯鏈接器需已經配置 –with-sysroot 選項才能起作用。也就是說，-rpath指定的路徑會被記錄在生成的可執行程序中，用於運行時查找需要加載的動態庫。-rpath-link 則只用於鏈接時查找。

##鏈接搜索順序
直接man ld。The linker uses the following search paths to locate required shared libraries:


```sh
1.  Any directories specified by -rpath-link options.
2.  Any directories specified by -rpath options.  The difference between -rpath and -rpath-link is that directories specified by -rpath options are included in the executable and used at runtime, whereas the -rpath-link option is only effective at link time. Searching -rpath in this way is only supported by native linkers and cross linkers which have been configured with the --with-sysroot option.
3.  On an ELF system, for native linkers, if the -rpath and -rpath-link options were not used, search the contents of the environment variable "LD_RUN_PATH".
4.  On SunOS, if the -rpath option was not used, search any directories specified using -L options.
5.  For a native linker, the search the contents of the environment variable "LD_LIBRARY_PATH".
6.  For a native ELF linker, the directories in "DT_RUNPATH" or "DT_RPATH" of a shared library are searched for shared libraries needed by it. The "DT_RPATH" entries are ignored if "DT_RUNPATH" entries exist.
7.  The default directories, normally /lib and /usr/lib.
8.  For a native linker on an ELF system, if the file /etc/ld.so.conf exists, the list of directories found in that file.
If the required shared library is not found, the linker will issue a warning and continue with the link.

```


##gcc和鏈接選項的使用
在gcc中使用ld鏈接選項時，需要在選項前面加上前綴-Wl(是字母l，不是1，我曾多次弄錯），以區別不是編譯器的選項。

if the linker is being invoked indirectly, via a compiler driver (e.g. gcc) then all the linker command line options should be prefixed by -Wl, (or whatever is appropriate for the particular compiler driver) like this:

```sh
gcc -Wl,--start-group foo.o bar.o -Wl,--end-group
```

##rpath-link rptah說明
 
跨平臺編譯的時候時常會出現
rpath-link與rpath這兩個參數
 
簡單的來說:
rpath-link用途用來連結編譯的路徑與-L相同
rpath用途為編譯完成後執行環境的路徑指定
 
2012年9月13日星期四

## misc: options -rpath-link and -L
 
-L 用來指定搜尋路徑，根據這個路徑搜尋 -l 選項中的 library
 
假設:

```sh
1. main.c depends on liba.so
2. liba.so depends on libb.so
3. liba.so locates at /lib
4. libb.so locates at /usr/lib
```

則要編出 main.c 的 executable，正確的作法是:
 
gcc main.c -o main -L/lib -la -L/usr/lib -lb
 
PS: -L 所指定的目錄，不管順序與出現如何，會對所有的 -l library 生效，
也就是在上面的例子中雖然 -L/usr/lib 晚於 -la 出現，
但在找 liba.so 的時後是 /lib 與 /usr/lib 都會搜尋的。
 
今天問題是開發 main.cpp 時只用到了 liba.so 的 symbol，
我們不見得會知道 liba.so 的 dependency libb.so，
甚至或許 libb.so 還有其它的 dependency。
 
很自然的人的直覺只會這樣寫:  gcc main.c -o main -L/lib -la
 
link 階段需要 resolve 所有的 symbols (解決所有 dependency)
要把所有相關的 dependent libraries 全找出來又是不切實際的。
 
GNU ld 的設計中有個預設路徑會去自動搜尋在 link 階段所需要的 library，
在這個淺規則之下 gcc main.c -o main -L/lib -la 這個指令依舊能產生可執行檔，
原因是 /usr/lib 正好就是 GNU ld x86 版本的預設路徑之一 (另一個是 /lib)。
 
link liba.so 的時後會從 liba.so 的 dynamic section 中得知 liba.so depends on libb.so，
然後在 /usr/lib 中找到 libb.so，然後再 link 所有 libb.so。
 
 
Linux 系統上只要安裝 library，in default 一定會丟進 /usr/lib 下，
因此開發 x86 的程式只要有 library 加上版本有對，
不太會有 link 時找不到 library 的困擾。
 
embedded 開發裡就沒這麼爽，
因為在 cross compile 的時後 ld 的預設路徑裡 (<ld 執行檔路徑>/../lib 之類的)
通常只有基本的 libraries。
 
所以我們需要使用到 GNU ld 的 -rpath-link 這個 option，
這個 option 就是用來補強預設路徑。
 
假設:

```sh
1. main.c depends on liba.so
2. liba.so depends on libb.so
3. liba.so locates at /home/some_one/lib
4. libb.so locates at /home/some_one/lib
```

則 mips-linux-gcc main.cpp -o main -L/home/some_one/lib -la -rpath-link /home/some_one/lib
可以編出可執行檔。
 
-L/home/some_one/lib 用來對應 -la，找 liba.so 時用，
-rpath-link /home/some_one/lib 用來補充 mips-linux-gcc 預設路徑，
解決所有的 dependency 所用 (在這個 case 可以找到 libb.so)。

