#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef char DataType;
#include "LinkStack.h"
void main()
{
    LinkStack S;
    LStackNode* s;
    DataType ch[50], e, *p;
    InitStack(&S);
    printf("�������ջ���ַ���\n");
    gets(ch);
    p = &ch[0];

    while (*p) {
        PushStack(S, *p);
        p++;
    }

    printf("��ǰջ����Ԫ���ǣ�");

    if (GetTop(S, &e) == 0) {
        printf("ջ�ѿգ�");
        return;
    } else {
        printf("%4c\n", e);
    }

    printf("��ǰջ�е�Ԫ�ظ����ǣ�%d\n", StackLength(S));
    printf("Ԫ�س�ջ�������ǣ�");

    while (!StackEmpty(S)) {
        PopStack(S, &e);
        printf("%4c", e);
    }

    printf("\n");
}
