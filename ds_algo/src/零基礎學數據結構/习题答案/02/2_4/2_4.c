#include<stdio.h>
#include<math.h>
#define N 30
void Josephus();

void Josephus(int a[], int n, int s, int m)
/*Լɪ�����⣬����Ȧ���˵�������δ����������*/
{
    int i, j, s1, t;
    s1 = s;             /*��ʼ���������*/

    for (i = 1; i <= n; i++) { /*��ʼ��*/
        a[i - 1] = i;
    }

    for (i = n; i >= 2; i--) { /*iΪ��ǰȦ�е�����*/
        s1 = (s1 + m - 1) % i; /*s1Ϊ��Ҫ��Ȧ�����*/

        if (s1 == 0) {  /*���s1=0˵������Ҫ��Ȧ���˵����Ϊs1*/
            s1 = i;
        }

        /*�����s1���˳�Ȧ���������Ϊs1���Ƶ��������ĩβ*/
        t = a[s1 - 1];

        for (j = s1; j <= i - 1; j++) { /*��s1���������ǰ��*/
            a[j - 1] = a[j];
        }

        a[i - 1] = t; /*�����Ϊs1�����洢��a��ĩβ*/
    }
}

void main()
{
    int i, a[N];
    int n = 13, m = 3, s = 1;
    Josephus(a, n, s, m);
    printf("��Ȧ�����α��Ϊ:");

    for (i = n - 1; i >= 0; i--) {
        printf("%-4d", a[i]);
    }

    printf("\n");
}




