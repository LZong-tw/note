/*����ͷ�ļ�*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
/*�궨��͵��������Ͷ���*/
#define ListSize 100
typedef int DataType;
typedef struct Node {
    DataType data;
    struct Node* next;
} ListNode, *LinkList;
#include"LinkList.h"
void ListOrder(LinkList L)
/*������L���о͵�����*/
{
    ListNode* p, *r, *t, *q;

    p = L->next;            /*p��ָ�������Ľ��ĵ�һ�����*/

    L->next = NULL;         /*��ʼʱ������������Ϊ��*/

    while (p != NULL) {     /*�������������Ϊ��*/
        if (L->next == NULL) {  /*����ǵ�һ����㣬����Ϊ��һ��������L*/
            L->next = p;
            r = p->next;
            p->next = NULL;
            p = r;
        }

        else {                  /*pָ�������Ľ�㣬��Lָ����Ѿ��ź���������в��Ҳ���λ��*/
            r = L;
            q = L->next;

            while (q != NULL && p->data > q->data) { /*��qָ����������Ѱ�Ҳ���λ��*/
                r = q;
                q = q->next;
            }

            t = p->next;        /*tָ��p����һ����㣬����������ָ��λ��*/
            p->next = r->next;  /*�����*p���뵽���*r�ĺ���*/
            r->next = p;
            p = t;              /*pָ����һ��������Ľ��*/
        }
    }

}

void DispList(LinkList L)
/*�������L�е�Ԫ��*/
{
    ListNode* p;
    p = L->next;

    while (p != NULL) {
        printf("%4d", p->data);
        p = p->next;
    }

    printf("\n");
}
void main()
{
    LinkList L;
    ListNode* p;
    int i, m, n;
    DataType a[] = {7, 3, 13, 11, 10, 23, 45, 6};
    n = 8;
    InitList(&L);

    for (i = 0; i < n; i++) {
        InsertList(L, i + 1, a[i]);
    }

    printf("����ǰ��˳���L�е�Ԫ������Ϊ��");
    DispList(L);
    ListOrder(L);
    printf("�����˳���L�е�Ԫ������Ϊ��");
    DispList(L);
}
