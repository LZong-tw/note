#include<stdio.h>
#include<malloc.h>
typedef char DataType;
#define MaxSize 100
typedef struct Node {
    DataType data;
    struct Node* next;
} LStackNode, *LinkStack;
void InitStack(LinkStack* top)
/*����ջ��ʼ��Ϊ�ա���̬����ͷ��㣬����ͷ����ָ������Ϊ�ա�*/
{
    if ((*top = (LinkStack)malloc(sizeof(LStackNode))) ==
        NULL) { /*Ϊͷ������һ���洢�ռ�*/
        exit(-1);
    }

    (*top)->next = NULL;            /*����ջ��ͷ���ָ������Ϊ��*/
}

int PushStack(LinkStack top, DataType e)
/*��ջ��������Ҫ������ĵ�һ�����ǰ����һ���½�㣬��ջ�ɹ�����1*/
{
    LStackNode*
    p;      /*����ָ���i��Ԫ�ص�ǰ�����ָ��pre��ָ��pָ�������ɵĽ��*/

    if ((p = (LStackNode*)malloc(sizeof(LStackNode))) == NULL) {
        printf("�ڴ����ʧ��!");
        exit(-1);
    }

    p->data = e;        /*ָ��pָ��ͷ���*/
    p->next = top->next;
    top->next = p;
    return 1;
}
int PopStack(LinkStack top, DataType* e)
/*ɾ���������еĵ�i��λ�õĽ�㡣ɾ���ɹ�����1��ʧ�ܷ���0*/
{
    LStackNode* p;
    p = top->next;

    if (!p) {                       /*�ж���ջ�Ƿ�Ϊ��*/
        printf("ջ�ѿ�");
        return 0;
    }

    top->next = p->next;            /*��ջ�����������Ͽ�������ջ*/
    *e = p->data;                   /*����ջԪ�ظ�ֵ��e*/
    free(p);                        /*�ͷ�pָ��Ľ��*/
    return 1;
}

void DestroyStack(LinkStack top)
/*����ջ*/
{
    LStackNode* p, *q;
    p = top;

    while (!p) {
        q = p;
        p = p->next;
        free(q);
    }
}
int GetTop(LinkStack top, DataType* e)
/*ȡջ��Ԫ��*/
{
    LStackNode* p;
    p = top->next;

    if (!p) {                       /*�ж���ջ�Ƿ�Ϊ��*/
        printf("ջ�ѿ�");
        return 0;
    }

    *e = p->data;               /*����ջԪ�ظ�ֵ��e*/
    return 1;
}
void main()
{
    char str[MaxSize];
    DataType e;
    LinkStack S;
    int i;
    InitStack(&S);
    printf("�������ַ�����");
    gets(str);

    for (i = 0; i < strlen(str); i++) {
        PushStack(S, str[i]);
    }

    printf("ջ��Ԫ���ǣ�");
    GetTop(S, &e);
    printf("%c\n", e);
    printf("���г�ջ��������ջ��Ԫ�������ǣ�");

    for (i = 0; i < strlen(str); i++) {
        PopStack(S, &e);
        printf("%4c", e);
    }

    printf("\n");
    DestroyStack(&S);

}