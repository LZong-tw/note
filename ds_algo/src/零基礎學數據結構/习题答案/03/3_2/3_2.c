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
void Interction(LinkList A, LinkList B, LinkList C)
/*����A��B�о�����ͬ��Ԫ�ز��뵽C��*/
{
    ListNode* pa, *pb, *pc;

    pa = A->next, pb = B->next;

    while (pa && pb) {  /*���A��B����Ϊ��*/
        if (pa->data <
            pb->data) { /*���A�е�Ԫ��С��B�е�Ԫ�أ��������A�к����Ԫ����B�е�ǰԪ�رȽ�*/
            pa = pa->next;
        } else if (pa->data >
                   pb->data) { /*���A�е�Ԫ�ش���B�е�Ԫ�أ��������B�к����Ԫ����A�е�ǰԪ�رȽ�*/
            pb = pb->next;
        } else { /*���A��BԪ����ȣ��򽫸�Ԫ�ز��뵽C��*/
            pc = (ListNode*)malloc(sizeof(ListNode));
            pc->data = pa->data;
            pc->next = C->next;
            C->next = pc;
            pa = pa->next;
            pb = pb->next;
        }
    }

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
    LinkList A, B, C;
    ListNode* p;
    int i, m, n;
    DataType a[] = {7, 3, 13, 11, 10, 23, 45, 6};
    DataType b[] = {6, 11, 7, 2, 8, 13};
    n = 8, m = 6;
    InitList(&A);
    InitList(&B);
    InitList(&C);

    for (i = 0; i < n; i++) {
        InsertList(A, i + 1, a[i]);
    }

    for (i = 0; i < m; i++) {
        InsertList(B, i + 1, b[i]);
    }

    printf("˳���A��Ԫ������Ϊ��");
    DispList(A);
    printf("˳���B��Ԫ������Ϊ��");
    DispList(B);
    InsertSort(A);
    InsertSort(B);
    printf("˳���A����������е�Ԫ������Ϊ��");
    DispList(A);
    printf("˳���B����������е�Ԫ������Ϊ��");
    DispList(B);
    Interction(A, B, C);
    printf("A��B�н�����Ԫ������Ϊ��");
    DispList(C);
}
