#include <stdio.h>          /*���������������*/
#define N 10
void MulArray1(int* x, int n);  /*��������Ϊ�����ĺ���ԭ��*/
void MulArray2(int* aPtr, int n); /*ָ����Ϊ�����ĺ���ԭ��*/
void main()
{
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    printf("ԭ�������е�Ԫ��Ϊ:\n");

    for (i = 0; i < N; i++) {
        printf("%4d", a[i]);
    }

    printf("\n");
    printf("����Ԫ�ص�һ�ηŴ�5����Ϊ:\n");
    MulArray1(a, N);            /*������������Ϊ�����ĺ���*/

    for (i = 0; i < N; i++) {
        printf("%4d", a[i]);
    }

    printf("\n");
    printf("����Ԫ�صڶ��ηŴ�5����Ϊ:\n");
    MulArray2(a, N);            /*����ָ����Ϊ�����ĺ���*/

    for (i = 0; i < N; i++) {
        printf("%4d", a[i]);
    }

    printf("\n");
}
void MulArray1(int b[], int n)
/*��������Ϊ������ʵ�ֺ�����*/
{
    int i;

    for (i = 0; i < n; i++) {
        b[i] = b[i] * 5;
    }
}
void MulArray2(int* aPtr, int n)
/*ָ����Ϊ������ʵ�֡�ͨ��ָ�����ÿһ��Ԫ�ء�*/
{
    int i;

    for (i = 0; i < n; i++) {
        *(aPtr + i) = *(aPtr + i) * 5;
    }
}