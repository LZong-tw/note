/*����ͷ�ļ�*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include "string.h"
/*�궨�����ջ���Ͷ���*/
typedef char DataType;
#include"LinkStack.h"                   /*������ջʵ���ļ�*/
int Match(DataType e, DataType ch);
void main()
{
    LinkStack S;
    char* p;
    DataType e;
    DataType ch[60];
    InitStack(&S);                  /*��ʼ����ջ*/
    printf("����������ŵı��ʽ('{}','[]','()').\n");
    gets(ch);
    p = ch;

    while (*p) {
        switch (*p) {
        case '(':
        case '[':
        case '{':
            PushStack(S, *p++);
            break;

        case ')':
        case ']':
        case '}':
            if (StackEmpty(S)) {
                printf("ȱ��������.\n");
                return;
            } else {
                GetTop(S, &e);

                if (Match(e, *p)) {
                    PopStack(S, &e);
                } else {
                    printf("�������Ų����.\n");
                    return;
                }
            }

        default:
            p++;
        }
    }

    if (StackEmpty(S)) {
        printf("����ƥ��.\n");
    } else {
        printf("ȱ��������.\n");
    }
}


int Match(DataType e, DataType ch)
{
    if (e == '(' && ch == ')') {
        return 1;
    } else if (e == '[' && ch == ']') {
        return 1;
    } else if (e == '{' && ch == '}') {
        return 1;
    } else {
        return 0;
    }

}