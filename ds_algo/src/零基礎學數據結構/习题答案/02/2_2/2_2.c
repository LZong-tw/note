#include<stdio.h>
#include<math.h>
#define N 10
int a[N];
int Rd(int n, int k)
/*��ʽ�ֽ�*/
{
    int j, c;

    for (c = n; c >= 1; c--) {      /*���ֽ������n*/
        if (c <= a[k -
                     1]) {        /*�����ǰ�ֽ����cС�ڵ�����һ�������������У�����c���浽������*/
            a[k] = c;

            if (c == n) {           /*���c==n���������ʽ�ķֽ�*/
                printf("%d=%d", a[0], a[1]);

                for (j = 2; j <= k; j++) {
                    printf("+%d", a[j]);
                }

                printf("\n");
            } else {
                Rd(n - c, k + 1);    /*����n-c���зֽ⣬�ֽ����k+1������*/
            }
        }
    }

}

void main()
{
    int n = 4;
    a[0] = 4;
    Rd(n, 1);
}