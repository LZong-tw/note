#include<stdio.h>           /*������������ͷ�ļ�*/
#define N 50
int NonRecSum(int a[], int n);          /*��������*/
void main()
{
    int i, n, a[N];
    printf("������һ��50���ڵ���Ȼ����");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {   /*��ǰn����Ȼ�����������a��*/
        a[i] = i + 1;
    }

    printf("ǰ%d����Ȼ���ĺ�Ϊ��%d\n", n, NonRecSum(a, n));
}
int NonRecSum(int a[], int n)
/*�ǵݹ�������aǰn�����ĺ�*/
{
    int i, sum = 0;

    for (i = 0; i < n; i++) {   /*ͨ��������n����Ȼ���ĺ�*/
        sum += i;
    }

    return sum;
}
