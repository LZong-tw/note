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
void InsertSort(LinkList L);
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
    DataType a[] = {87, 34, 22, 93, 102, 56, 39, 21};
    InitList(&L);
    CreateList(L, a, n);
    printf("����ǰ��\n");

    for (p = L->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }

    printf("\n");
    InsertSort(L);
    printf("�����\n");

    for (p = L->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }

    printf("\n");
}

void InsertSort(LinkList L)
/*����Ĳ�������*/
{
    ListNode* p = L->next, *pre, *q;
    L->next = NULL;         /*��ʼʱ������������Ϊ��*/

    while (p != NULL) {     /*p��ָ�������Ľ��*/
        if (L->next ==
            NULL) { /*���*p�ǵ�һ����㣬����뵽L����������������һ������ָ����Ϊ��*/
            L->next = p;
            p = p->next;
            L->next->next = NULL;
        } else {            /*pָ�������Ľ�㣬��Lָ����Ѿ��ź���������в��Ҳ���λ��*/
            pre = L;
            q = L->next;

            while (q != NULL && q->data < p->data) { /*��qָ����������Ѱ�Ҳ���λ��*/
                pre = q;
                q = q->next;
            }

            q = p->next;                    /*qָ��p����һ����㣬����������ָ��λ��*/
            p->next = pre->next;            /*�����*p���뵽���*pre�ĺ���*/
            pre->next = p;
            p = q;                          /*pָ����һ��������Ľ��*/
        }
    }
}
