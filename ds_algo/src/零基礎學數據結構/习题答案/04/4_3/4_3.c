//����ѭ�����ǰ40��
#include <stdio.h>
#include<string.h>
#include <stdio.h>
#define N 40
int Fib(int n);
int Fib2(int x)
/*fibonacci���еķǵݹ�ʵ��*/
{
    int n = 20;
    long f[N] = {0, 1};
    int i;

    for (i = 2; i < n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    printf("�ǵݹ���ã�fibonacci���е�ǰ%d�����ǣ�", n);

    for (i = 0; i < n - 1; i++) {
        printf("F%d==%d,", i + 1, f[i]);
    }

    printf("F%d==%d\n", i + 1, f[i]);
    return f[x - 1];
}


void main()
{
    int n, x;
    printf("������һ��������n(0<n<20)\n");
    scanf("%d", &n);
    printf("�ݹ���ã���%d�����ǣ�%d\n", n, Fib(n));
    x = Fib2(n);
    printf("�ǵݹ���ã���%d�����ǣ�%d\n", n, x);

}
int Fib(int n)
/*fibonacci���еĵݹ�ʵ��*/
{
    if (n == 1) {
        return 0;
    } else if (n == 2 || n == 3) {
        return 1;
    } else {
        return Fib(n - 1) + Fib(n - 2);
    }
}
