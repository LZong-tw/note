#include<stdio.h>
#include<string.h>
typedef char DataType;
#include"SeqStack.h"
#define MaxSize 50
typedef struct { /*������ջ�����Ͷ���*/
    float data[MaxSize];
    int top;
} OpStack;
void TranslateExpress(char s1[], char s2[]);
float ComputeExpress(char s[]);
void main()
{
    char a[MaxSize], b[MaxSize];
    float f;
    printf("������һ���������ʽ��\n");
    gets(a);
    printf("��׺���ʽΪ��%s\n", a);
    TranslateExpress(a, b);
    printf("��׺���ʽΪ��%s\n", b);
    f = ComputeExpress(b);
    printf("��������%f\n", f);
}
float ComputeExpress(char a[])
/*�����׺���ʽ��ֵ*/
{
    OpStack S;
    int i = 0, value;
    float x1, x2;
    float result;
    S.top = -1;

    while (a[i] != '\0') {
        if (a[i] != ' ' && a[i] >= '0' &&
            a[i] <= '9') { /*�����ǰ�ַ��������ַ�������ת��Ϊ���ֲ�����ջ��*/
            value = 0;

            while (a[i] != ' ') {
                value = 10 * value + a[i] - '0';
                i++;
            }

            S.top++;
            S.data[S.top] = value;
        } else {        /*�����ǰ�ַ�������������ջ�е����ݽ�����ֵ������������浽ջ��*/
            switch (a[i]) {

            case '+':
                x1 = S.data[S.top];
                S.top--;
                x2 = S.data[S.top];
                S.top--;
                result = x1 + x2;
                S.top++;
                S.data[S.top] = result;
                break;

            case '-':
                x1 = S.data[S.top];
                S.top--;
                x2 = S.data[S.top];
                S.top--;
                result = x2 - x1;
                S.top++;
                S.data[S.top] = result;
                break;

            case '*':
                x1 = S.data[S.top];
                S.top--;
                x2 = S.data[S.top];
                S.top--;
                result = x1 * x2;
                S.top++;
                S.data[S.top] = result;
                break;

            case '/':
                x1 = S.data[S.top];
                S.top--;
                x2 = S.data[S.top];
                S.top--;
                result = x2 / x1;
                S.top++;
                S.data[S.top] = result;
                break;
            }

            i++;
        }
    }

    if (!S.top != -1) {
        result = S.data[S.top];
        S.top--;

        if (S.top == -1) {
            return result;
        } else {
            printf("���ʽ����");
            exit(-1);
        }
    }
}
void TranslateExpress(char str[], char exp[])
/*����׺���ʽת��Ϊ��׺���ʽ*/
{
    SeqStack S;
    char ch;
    DataType e;
    int i = 0, j = 0;
    InitStack(&S);
    ch = str[i];
    i++;

    while (ch != '\0') {
        switch (ch) {
        case'(':    /*��������ջ*/
            PushStack(&S, ch);
            break;

        case')':    /*�����ǰ�ַ��������ţ���ջ�е��ַ���ջ��ֱ��ջ�е�һ�������ų�ջΪֹ*/
            while (GetTop(S, &e) && e != '(') {
                PopStack(&S, &e);
                exp[j] = e;
                j++;
            }

            PopStack(&S, &e); /*�����ų�ջ*/
            break;

        case'+':
        case'-':
            while (!StackEmpty(S) && GetTop(S, &e) &&
                   e != '(') { /*�����ǰ�ַ���+�Ż�-�ţ���ջ���ַ���ջ��ֱ������������Ϊֹ*/
                PopStack(&S, &e);
                exp[j] = e;
                j++;
            }

            PushStack(&S, ch); /*����ǰ�ַ���ջ*/
            break;

        case'*':
        case'/':
            while (!StackEmpty(S) && GetTop(S, &e) && e == '/' ||
                   e == '*') { /*�����ǰ�ַ���*�Ż�����/�ţ���ջ���ַ���ջ*/
                PopStack(&S, &e);
                exp[j] = e;
                j++;
            }

            PushStack(&S, ch);  /*��ǰ�ַ���ջ*/
            break;

        case' ':
            break;

        default:                /*���������ַ�*/
            while (ch >= '0' && ch <= '9') {
                exp[j] = ch;
                j++;
                ch = str[i];
                i++;
            }

            i--;
            exp[j] = ' ';
            j++;
        }

        ch = str[i];
        i++;
    }

    while (!StackEmpty(S)) {
        PopStack(&S, &e);
        exp[j] = e;
        j++;
    }

    exp[j] = '\0';
}
