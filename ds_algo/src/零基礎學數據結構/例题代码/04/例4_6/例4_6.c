#include<stdio.h>
#define Max 100
int fact1(int n);
int fact2(int n);
void main()
{
    int f, n;
    printf("������һ��������(n<15)��");
    scanf("%d", &n);
    printf("�ݹ�ʵ��n�Ľ׳�:");
    f = fact1(n);
    printf("n!=%4d\n", f);
    f = fact2(n);
    printf("����ջ�ǵݹ�ʵ��n�Ľ׳�:");
    printf("n!=%4d\n", f);
}
int fact1(int n)
{
    if (n == 1) {
        return 1;
    } else {
        return n * fact1(n - 1);
    }
}
int fact2(int n)
{
    int s[Max][2], top = -1;
    top++;
    s[top][0] = n;
    s[top][1] = 0;

    do {
        if (s[top][0] == 1) {
            s[top][1] = 1;
        }

        if (s[top][0] > 1 && s[top][1] == 0) {
            top++;
            s[top][0] = s[top - 1][0] - 1;
            s[top][1] = 0;
        }

        if (s[top][1] != 0) {
            s[top - 1][1] = s[top][1] * s[top - 1][0];
            top--;
        }
    } while (top > 0);

    return s[0][1];
}
