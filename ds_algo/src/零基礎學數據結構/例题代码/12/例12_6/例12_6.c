/*����ͷ�ļ�*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int DataType;   /*Ԫ�����Ͷ���Ϊ����*/
typedef struct Node {   /*���������Ͷ���*/
    DataType data;
    struct Node* next;
} ListNode, *LinkList;
#include"LinkList.h"
void SelectSort(LinkList L);
void CreateList(LinkList L, DataType a[], int n);
void CreateList(LinkList L, DataType a[], int n)
/*����������*/
{
    int i;

    for (i = 1; i <= n; i++) {
        InsertList(L, i, a[i - 1]);
    }
}
void main()
{
    LinkList L, p;
    int n = 8;
    DataType a[] = {45, 67, 21, 98, 12, 39, 81, 53};
    InitList(&L);
    CreateList(L, a, n);
    printf("����ǰ��\n");

    for (p = L->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }

    printf("\n");
    SelectSort(L);
    printf("�����\n");

    for (p = L->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }

    printf("\n");
}

void SelectSort(LinkList L)
/*������ʵ��ѡ�����򡣽������Ϊ���Σ�pָ��Ӧ������������֣�qָ��δ�����������*/
{
    ListNode* p, *q, *t, *s;
    p = L;

    while (p->next->next != NULL) {
        for (s = p, q = p->next; q->next != NULL; q = q->next) /*��qָ����б�������*/
            if (q->next->data <
                s->next->data) { /*���qָ��ָ���Ԫ��ֵС��sָ���Ԫ��ֵ����s=q*/
                s = q;
            }

        if (s != q) {       /*���*s�������һ����㣬��sָ��Ľ�����ӵ�pָ����������*/
            t = s->next;    /*�����*t��qָ���������ȡ��*/
            s->next = t->next;
            t->next = p->next; /*�����*t���뵽pָ���������*/
            p->next = t;
        }

        p = p->next;
    }
}
