/*����ͷ�ļ�*/
#include<stdio.h>
#include<stdlib.h>
/*���Ͷ���*/
#define StackSize 100
typedef char DataType;
#include "SSeqStack.h"      /*����ջ�Ļ������Ͷ���ͻ�������ʵ��*/
int GetTop(SSeqStack S, DataType* e, int flag);
int StackEmpty(SSeqStack S, int flag);
void main()
{
    SSeqStack S1, S2;           /*����һ��ջ*/
    int i;
    DataType a[] = {'a', 'b', 'c', 'd', 'e'};
    DataType b[] = {'x', 'y', 'z', 'r'};
    DataType e1, e2;
    InitStack(&S1);                 /*��ʼ��ջ*/
    InitStack(&S2);

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) { /*������a��Ԫ�����ν�ջ*/
        if (PushStack(&S1, a[i], 0) == 0) {
            printf("ջ���������ܽ�ջ��");
            return;
        }
    }

    for (i = 0; i < sizeof(b) / sizeof(b[0]); i++) { /*������a��Ԫ�����ν�ջ*/
        if (PushStack(&S2, b[i], 1) == 0) {
            printf("ջ���������ܽ�ջ��");
            return;
        }
    }

    if (GetTop(S1, &e1, 0) == 0) {
        printf("ջ�ѿ�");
        return;
    }

    if (GetTop(S2, &e2, 1) == 0) {
        printf("ջ�ѿ�");
        return;
    }

    printf("ջS1��ջ��Ԫ���ǣ�%c��ջS2��ջ��Ԫ����:%c\n", e1, e2);
    printf("S1��ջ��Ԫ�ش����ǣ�");
    i = 0;

    while (!StackEmpty(S1, 0)) { /*������a��Ԫ�����ν�ջ*/
        PopStack(&S1, &e1, 0);
        printf("%4c", e1);
    }

    printf("\n");
    printf("S2��ջ��Ԫ�ش����ǣ�");

    while (!StackEmpty(S2, 1)) { /*������a��Ԫ�����ν�ջ*/
        PopStack(&S2, &e2, 1);
        printf("%4c", e2);
    }

    printf("\n");
}
int GetTop(SSeqStack S, DataType* e, int flag)
/*ȡջ��Ԫ�ء���ջ��Ԫ��ֵ���ظ�e��������1��ʾ�ɹ������򷵻�0��ʾʧ�ܡ�*/
{
    switch (flag) {
    case 0:
        if (S.top[0] == 0) {
            return 0;
        }

        *e = S.stack[S.top[0] - 1];
        break;

    case 1:
        if (S.top[1] == StackSize - 1) {
            return 0;
        }

        *e = S.stack[S.top[1] + 1];
        break;

    default:
        return 0;
    }

    return 1;
}
int StackEmpty(SSeqStack S, int flag)
{
    switch (flag) {
    case 0:
        if (S.top[0] == 0) {
            return 1;
        }

        break;

    case 1:
        if (S.top[1] == StackSize - 1) {
            return 1;
        }

        break;

    default:
        return 0;
    }

    return 0;
}
