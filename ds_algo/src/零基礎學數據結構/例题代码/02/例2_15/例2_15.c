/*----------------����ͷ�ļ�����------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
/*----------------�ṹ�嶨�岿��-------------------------*/
struct Node {
    char name[10];
    int score;
    struct Node* next;
};
typedef struct Node ListNode;
/*--------------------������������--------------------------*/
ListNode* CreateList(int n);
void InsertList(ListNode* h, int i, char name[], int score, int n);
void DeleteList(ListNode* h, int i, int n);
void PrintList(ListNode* h);
/*----------------����ʵ�ֲ���------------------------*/
/*----------------��������------------------------*/
ListNode* CreateList(int n)
/*�������ĩ�˲����µĽ�㣬��������*/
{
    ListNode* head;
    ListNode* p, *pre;
    int i;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    pre = head;

    for (i = 1; i <= n; i++) {
        printf("input name of the %d student:", i);
        p = (ListNode*)malloc(sizeof(ListNode));    /*ΪҪ����Ľ������ڴ�ռ�*/
        scanf("%s", &p->name);
        printf("input score of the %d student:", i);
        scanf("%d", &p->score);
        pre->next = p;                              /*��pָ����½���������*/
        pre = p;
    }

    p->next = NULL;
    return head;
}
/*--------------------�������Ԫ��------------------*/
void PrintList(ListNode* h)
{
    ListNode* p;
    p = h->next;

    while (p) {
        printf("%s,%d", p->name, p->score);
        p = p->next;
        printf("\n");
    }
}
/*--------------------������------------------*/
void main()
{
    ListNode* h;
    int i = 1, n, score;
    char name[10];

    while (i) {
        /*������ʾ��Ϣ*/
        printf("1--�����µ�����\n");
        printf("2--���Ԫ��\n");
        printf("3--ɾ��Ԫ��\n");
        printf("4--�����ǰ���е�Ԫ��\n");
        printf("0--�˳�\n");

        scanf("%d", &i);

        switch (i) {
        case 1:
            printf("intput the number of elements.");                   /*���봴��������ĸ���*/
            scanf("%d", &n);
            h = CreateList(n);              /*��������*/
            printf("list elements is:\n");
            PrintList(h);                   /*�������Ԫ��*/
            break;

        case 2:
            printf("input the position. of insert element:");
            scanf("%d", &i);                /*������ĵ�i��λ�ò���*/
            printf("input name of the student:");
            scanf("%s", name);
            printf("input score of the student:");
            scanf("%d", &score);
            InsertList(h, i, name, score, n); /*������*/
            printf("list elements is:\n");
            PrintList(h);
            break;

        case 3:
            printf("input the position. of delete element:");
            scanf("%d", &i);
            DeleteList(h, i, n);            /*ɾ������ĵ�i�����*/
            printf("list elements is:\n");
            PrintList(h);
            break;

        case 4:
            printf("list elements is:\n");
            PrintList(h);
            break;

        case 0:
            return;
            break;

        default:
            printf("ERROR!Try again!\n\n");
        }
    }

}
/*-----------------����������--------------------------*/
void InsertList(ListNode* h, int i, char name[], int e, int n)
{
    ListNode* q, *p;
    int j;

    if (i < 1 || i > n + 1) {
        printf("Error!Please input again.\n");
    } else {
        j = 0;
        p = h;

        while (j < i - 1) {
            p = p->next;
            j++;
        }

        q = (ListNode*)malloc(sizeof(ListNode)); /*ΪҪ����Ľ������ڴ�ռ�*/
        strcpy(q->name, name);
        q->score = e;
        q->next = p->next; /*���½����뵽������*/
        p->next = q;
    }
}
/*----------------ɾ��������------------------*/
void DeleteList(ListNode* h, int i, int n)
{
    ListNode* p, *q;
    int j;
    char name[10];
    int score;

    if (i < 1 || i > n) {
        printf("Error!Please input again.\n");
    } else {
        j = 0;
        p = h;

        while (j < i - 1) {
            p = p->next;
            j++;
        }

        q = p->next;                            /*qָ��Ľ��ΪҪɾ���Ľ��*/
        p->next = q->next;
        strcpy(name, q->name);
        score = q->score;
        free(q);                                /*�ͷ�qָ��Ľ��*/
        printf("name=%s,score=%d\n", name, score);
    }
}
