/*����ͷ�ļ�*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/*���Ͷ���*/
typedef int DataType;
typedef struct Node {
    DataType data;
    struct Node* prior;
    struct Node* next;
} DListNode, *DLinkList;
/*��������*/

void PrintDList(DLinkList head);

int InsertDList(DLinkList head, int i, char e);
/*����ʵ��*/
int InitDList(DLinkList* head)
/*��ʼ��˫��ѭ������*/
{
    *head = (DLinkList)malloc(sizeof(DListNode));

    if (!head) {
        return -1;
    }

    (*head)->next = *head;          /*ʹͷ����priorָ���nextָ��ָ���Լ�*/
    (*head)->prior = *head;
    return 1;
}

int InsertDList(DLinkList* L, int i, char e)
/*��˫��ѭ������ĵ�i��λ�ò���Ԫ��e����˫��ѭ������*/
{
    DListNode* s, *p;
    int j;
    p = (*L)->next;
    j = 1;

    /*���������е�i�����*/
    while (p != *L && j < i) {
        p = p->next;
        j++;
    }

    if (j > i) {        /*���Ҫλ�ò���ȷ������NULL*/
        return 0;
    }

    s = (DListNode*)malloc(sizeof(DListNode));

    if (!s) {
        return -1;
    }

    s->data = e;
    /*��s�����뵽˫��ѭ������*/
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return 1;
}
void InvertDList(DLinkList* L)
/*��˫��ѭ������L�͵�����*/
{
    DListNode* p, *q, *r;
    p = (*L)->next;                     /*pָ���һ�����*/

    if ((*L) != NULL && (*L) != (*L)->next) { /*�������L��Ϊ��*/
        /*������L�ĵ�һ���������*/
        q = p->next;
        (*L)->next = p;
        p->prior = (*L);
        (*L)->next->next = (*L);
        (*L)->prior = p;

        /*������L��ÿ��������β��뵽L��ͷ��*/
        while (q != *L) {
            r = q->next;        /*rָ����һ�������õĽ��*/
            q->next = (*L)->next;
            (*L)->next->prior = q;
            q->prior = (*L);
            (*L)->next = q;
            q = r;              /*pָ����һ�������õĽ��*/
        }
    }
}

void main()
{
    DLinkList L;

    DListNode* p;
    int i, m, n;
    DataType a[] = {7, 3, 13, 11, 10, 23, 45, 6};
    n = 8;
    InitDList(&L);

    for (i = 0; i < n; i++) {
        InsertDList(&L, i + 1, a[i]);
    }

    printf("����ǰ��˳���L�е�Ԫ������Ϊ��");
    PrintDList(L);
    InvertDList(&L);
    printf("���ú�˳���L�е�Ԫ������Ϊ��");
    PrintDList(L);
}
void PrintDList(DLinkList head)
/*���˫��ѭ�������е�ÿһ��Ԫ��*/
{
    DListNode* p;
    p = head->next;

    while (p != head) {
        printf("%4d", p->data);
        p = p->next;
    }

    printf("\n");
}
