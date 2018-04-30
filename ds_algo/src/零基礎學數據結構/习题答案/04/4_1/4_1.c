/*����ͷ�ļ�*/
#include<stdio.h>
#include<stdlib.h>
/*���Ͷ���*/
#define StackSize 100
typedef char DataType;
typedef struct {
    DataType stack[StackSize];
    int top;
} SeqStack;
void InitStack(SeqStack* S)
/*ջ�ĳ�ʼ������*/
{
    S->top = 0;
}
int PushStack(SeqStack* S, DataType e)
/*��ջ��������ջ�ɹ�����1�����򷵻�0*/
{
    if (S->top >= StackSize - 1) { /*�ڽ�ջ����֮ǰ���жϹ���ջ�Ƿ�Ϊ��*/
        return 0;
    } else {
        S->stack[S->top] = e;   /*Ԫ�ؽ�ջ*/
        S->top++;               /*�޸�ջ��ָ��*/
        return 1;
    }
}

int PopStack(SeqStack* S, DataType* e)
/*��ջ��Ԫ�س�ջ�����ջΪ�գ��򷵻�0������ջ��Ԫ�س�ջ����ֵ��e������1*/
{

    if (S->top == 0) {          /*���ջΪ�գ��򷵻�0����ʾ��ջ����ʧ��*/
        return 0;
    } else {
        S->top--;               /*�޸�ջ��ָ��*/
        *e = S->stack[S->top];  /*����ջ��Ԫ�ظ�ֵ��e*/
        return 1;
    }
}
int StackEmpty(SeqStack S)
/*�ж�ջ�Ƿ�Ϊ�ա����ջΪ�գ��򷵻�1�����򷵻�0*/
{
    if (S.top == 0) {
        return 1;
    } else {
        return 0;
    }
}
int GetTop(SeqStack S, DataType* e)
/*����ջ��Ԫ�ء�*/
{
    if (S.top == 0) { /*���ջΪ�գ��򷵻�0����ʾ��ջ����ʧ��*/
        return 0;
    } else {
        *e = S.stack[S.top - 1];    /*����ջ��Ԫ�ظ�ֵ��e*/
    }

}
void main()
{
    SeqStack S;                     /*����һ��ջ*/
    int i;
    DataType str[StackSize];
    DataType e;
    InitStack(&S);                  /*��ʼ��ջ*/
    printf("�������ַ���");
    gets(str);

    for (i = 0; i < strlen(str); i++) { /*���ַ���str�е��ַ����ν�ջ*/
        if (PushStack(&S, str[i], 0) == 0) {
            printf("ջ���������ܽ�ջ��");
            return;
        }
    }

    if (GetTop(S, &e) == 0) {   /*ȡջ��Ԫ��*/
        printf("ջ�ѿ�");
        return;
    }

    printf("ջS��ջ��Ԫ���ǣ�%c\n", e);
    printf("��ջS��ջ��Ԫ�ش����ǣ�");

    while (!StackEmpty(S)) {    /*���ν�ջ��Ԫ�س�ջ�����*/
        PopStack(&S, &e);
        printf("%4c", e);
    }

    printf("\n");
}

