/*����ͷ�ļ�*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include "string.h"
/*�궨�����ջ���Ͷ���*/
typedef char DataType;
#include"SeqStack.h"                    /*������ջʵ���ļ�*/
void LineEdit();
void LineEdit()
{
    SeqStack S;
    char ch;
    DataType e;
    DataType a[50];
    int i, j = 0;
    InitStack(&S);
    printf("�����ַ�����(#��ʾǰһ���ַ���Ч��@��ʾ��ǰ���ַ���Ч).\n");
    ch = getchar();

    while (ch != '\n') {
        switch (ch) {
        case '#':
            if (!StackEmpty(S)) {
                PopStack(&S, &ch);
            }

            break;

        case '@':
            ClearStack(&S);
            break;

        default:
            PushStack(&S, ch);
        }

        ch = getchar();
    }

    while (!StackEmpty(S)) {
        PopStack(&S, &e);
        a[j++] = e;
    }

    for (i = j - 1; i >= 0; i--) {
        printf("%c", a[i]);
    }

    printf("\n");
    ClearStack(&S);
}

void main()
{
    LineEdit();

}