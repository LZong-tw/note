#include<stdio.h>
#include<stdlib.h>
typedef char DataType;
#include "SeqStack.h"
void main()
{
    SeqStack S;
    int i;
    DataType a[] = {'a', 'b', 'c', 'd', 'e'};
    DataType e;
    InitStack(&S);

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        if (PushStack(&S, a[i]) == 0) {
            printf("ջ���������ܽ�ջ��");
            return;
        }
    }

    printf("��ջ��Ԫ���ǣ�");

    if (PopStack(&S, &e) == 1) {
        printf("%4c", e);
    }

    if (PopStack(&S, &e) == 1) {
        printf("%4c", e);
    }

    printf("\n");
    printf("��ǰջ����Ԫ���ǣ�");

    if (GetTop(S, &e) == 0) {
        printf("ջ�ѿգ�");
        return;
    } else {
        printf("%4c\n", e);
    }

    if (PushStack(&S, 'f') == 0) {
        printf("ջ���������ܽ�ջ��");
        return;
    }

    if (PushStack(&S, 'g') == 0) {
        printf("ջ���������ܽ�ջ��");
        return;
    }

    printf("��ǰջ�е�Ԫ�ظ����ǣ�%d\n", StackLength(S));
    printf("Ԫ�س�ջ�������ǣ�");

    while (!StackEmpty(S)) {
        PopStack(&S, &e);
        printf("%4c", e);
    }

    printf("\n");
}
