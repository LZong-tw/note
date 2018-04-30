/*����ͷ�ļ�*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/*���Ͷ���*/
typedef int DataType;

typedef struct node {
    DataType data;
    struct node* prior, *next;
} DListNode, *DLinkList;
DListNode* GetElem(DLinkList head, int i);
void PrintDList(DLinkList head);
int CreateDList(DLinkList head, int n);
int InsertDList(DLinkList head, int i, char e);
int InitDList(DLinkList* head);
void MergeDLink(DLinkList A, DLinkList B);
void main()
{
    DLinkList A, B;
    int n;
    int pos;
    char e;
    InitDList(&A);
    printf("����������A��Ԫ�ظ�����");
    scanf("%d", &n);
    CreateDList(A, n);
    printf("����A�е�Ԫ�أ�");
    PrintDList(A);
    InitDList(&B);
    printf("����������B��Ԫ�ظ�����");
    scanf("%d", &n);
    CreateDList(B, n);
    printf("����B�е�Ԫ�أ�");
    PrintDList(B);
    MergeDLink(A, B);
    printf("����A��B�ϲ����Ԫ�أ�");
    PrintDList(A);
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

void MergeDLink(DLinkList A, DLinkList B)
{
    DListNode* p, *q, *r, *qt, *pt;
    p = A->next;
    q = B->next;
    A->prior = A->next = A;
    r = A;

    while (p != A && q != B)
        if (p->data <= q->data) {
            pt = p->next;
            p->next = r->next;
            p->prior = r;
            r->next->prior = p;
            r->next = p;
            r = p;
            p = pt;
        } else {
            qt = q->next;
            q->next = r->next;
            q->prior = r;
            r->next->prior = q;
            r->next = q;
            r = q;
            q = qt;
        }

    if (p != A) {
        r->next = p;
        p->prior = r;
    } else if (q != B) {
        r->next = q;
        q->prior = r;
        B->prior->next = A;
        A->prior = B->prior;
    }

    free(B);
}
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
int CreateDList(DLinkList head, int n)
/*����˫��ѭ������*/
{
    DListNode* s, *q;
    int i;
    DataType e;
    q = head;

    for (i = 1; i <= n; i++) {
        printf("�����%d��Ԫ��", i);
        scanf("%d", &e);
        s = (DListNode*)malloc(sizeof(DListNode));
        s->data = e;
        /*�������ɵĽ����뵽˫��ѭ������*/
        s->next = q->next;
        q->next = s;
        s->prior = q;
        head->prior = s;            /*����Ҫע��ͷ����priorָ���²���Ľ��*/
        q = s;                      /*qʼ��ָ�����һ�����*/
    }

    return 1;
}
int InsertDList(DLinkList head, int i, DataType e)
/*��˫��ѭ������ĵ�i��λ�ò���Ԫ��e������ɹ�����1�����򷵻�0*/
{
    DListNode* p, *s;
    p = GetElem(head, i);           /*���������е�i�����*/

    if (!p) {
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
DListNode* GetElem(DLinkList head, int i)
/*���Ҳ����λ�ã��ҵ����ظý���ָ�룬���򷵻�NULL*/
{
    DListNode* p;
    int j;
    p = head->next;
    j = 1;

    while (p != head && j < i) {
        p = p->next;
        j++;
    }

    if (p == head || j > i) {       /*���Ҫλ�ò���ȷ������NULL*/
        return NULL;
    }

    return p;
}
