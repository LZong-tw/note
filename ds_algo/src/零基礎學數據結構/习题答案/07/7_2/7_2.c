#include<stdio.h>
#define N 20

void PrintMatrix(int a[N][N], int n)
/*��ӡ��������*/
{
    int i, j, k, m;
    k = 1;

    for (i = 0; i < n / 2; i++) {
        for (j = i; j < n - i; j++) { /*��ӡ�������*/
            a[i][j] = k++;
        }

        for (j = i + 1; j < n - i; j++) { /*��ӡ�ұߵ���*/
            a[j][n - i - 1] = k++;
        }

        for (j = n - i - 2; j >= i; j--) { /*��ӡ�������*/
            a[n - i - 1][j] = k++;
        }

        for (j = n - i - 2; j >= i + 1; j--) { /*��ӡ��ߵ���*/
            a[j][i] = k++;
        }
    }

    if (n % 2 != 0) {           /*���n�������������һ��������*/
        a[n / 2][n / 2] = k;
    }
}
void main()
{
    int a[N][N], n = 5, i, j;
    PrintMatrix(a, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d", a[i][j]);
        }

        printf("\n");
    }

}