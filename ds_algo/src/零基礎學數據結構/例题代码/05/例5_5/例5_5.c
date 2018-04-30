/*����ͷ�ļ�*/
#include<stdio.h>
#include<malloc.h>
typedef int DataType;               /*������ʽ����Ԫ�ص�����Ϊ��������*/
#define MaxSize 100
#include "LinkQueue.h"
void PrintArray(int a[], int n);
void YangHuiTriangle(int N);
void YangHuiTriangle(int N)
/*��ʽ����ʵ�ִ�ӡ�������*/
{
    int i, j, k, n;
    DataType e, t;
    int temp[MaxSize];              /*����һ����ʱ���飬���ڴ��ÿһ�е�Ԫ��*/
    LinkQueue Q;
    k = 0;
    InitQueue(&Q);                  /*��ʼ��������*/
    EnterQueue(&Q, 1);              /*��һ��Ԫ�����*/

    /*�������м�n-2�е�Ԫ��*/
    for (n = 2; n <= N;
         n++) {      /*������i��Ԫ�ز���ӣ�ͬʱ����i-1�е�Ԫ�ر�������ʱ������*/
        k = 0;
        EnterQueue(&Q, 1);          /*��i�еĵ�һ��Ԫ�����*/

        for (i = 1; i <= n - 2;
             i++) { /*���ö����е�i-1��Ԫ�ز�����i�е��м�i-2��Ԫ�ز������*/
            DeleteQueue(&Q, &t);
            temp[k++] = t;          /*����i-1�е�Ԫ�ش�����ʱ����*/
            GetHead(Q, &e);         /*ȡ��ͷԪ��*/
            t = t + e;              /*���ö��е�i-1��Ԫ�ز�����i��Ԫ��*/
            EnterQueue(&Q, t);
        }

        DeleteQueue(&Q, &t);
        temp[k++] = t;              /*����i-1�е����һ��Ԫ�ش�����ʱ����*/
        PrintArray(temp, k, N);
        EnterQueue(&Q, 1);          /*��i�е����һ��Ԫ�����*/

    }

    k = 0;                          /*�����һ��Ԫ�ش�������֮ǰ��Ҫ���±�k��Ϊ0*/

    while (!QueueEmpty(Q)) {        /*�����һ��Ԫ�ش�����ʱ����*/
        DeleteQueue(&Q, &t);
        temp[k++] = t;

        if (QueueEmpty(Q)) {
            PrintArray(temp, k, N);
        }
    }
}

void main()
{
    int n;
    printf("������Ҫ��ӡ��������n=:");
    scanf("%d", &n);
    YangHuiTriangle(n);
}
void PrintArray(int a[], int n, int N)
/*��ӡ�����е�Ԫ�أ�ʹ�ܹ�����ȷ����ʽ���*/
{
    int i;
    static count = 0;               /*��¼�������*/

    for (i = 0; i < N - count; i++) { /*��ӡ�ո�*/
        printf("   ");
    }

    count++;

    for (i = 0; i < n; i++) {       /*��ӡ�����е�Ԫ��*/
        printf("%6d", a[i]);
    }

    printf("\n");
}