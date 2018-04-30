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
#include"LinkList.h"                    /*����������ʵ���ļ�*/
void DelElem(LinkList A, LinkList B);   /*ɾ��A�г���B��Ԫ�صĺ�������*/
void DelElem2(LinkList A, LinkList B);
void main()
{
    int i;
    DataType a[] = {2, 3, 6, 7, 9, 14, 56, 45, 65, 67};
    DataType b[] = {3, 4, 7, 11, 34, 54, 45, 67};

    LinkList A, B;                  /*����������A��B*/
    ListNode* p;
    InitList(&A);                   /*��ʼ��������A*/
    InitList(&B);                   /*��ʼ��������B*/

    for (i = 1; i <= sizeof(a) / sizeof(a[0]);
         i++) { /*������a��Ԫ�ز��뵽������A��*/
        if (InsertList(A, i, a[i - 1]) == 0) {
            printf("λ�ò��Ϸ�");
            return;
        }
    }

    for (i = 1; i <= sizeof(b) / sizeof(b[0]); i++) { /*������b��Ԫ�ز��뵥����B��*/
        if (InsertList(B, i, b[i - 1]) == 0) {
            printf("λ�ò��Ϸ�");
            return;
        }
    }

    printf("������A�е�Ԫ����%d����\n", ListLength(A));

    for (i = 1; i <= ListLength(A); i++) { /*���������A�е�ÿ��Ԫ��*/
        p = Get(A, i);              /*���ص�����A�е�ÿ������ָ��*/

        if (p) {
            printf("%4d", p->data);    /*���������A�е�ÿ��Ԫ��*/
        }
    }

    printf("\n");
    printf("������B�е�Ԫ����%d����\n", ListLength(B));

    for (i = 1; i <= ListLength(B); i++) {
        p = Get(B, i);              /*���ص�����B�е�ÿ��ÿ������ָ��*/

        if (p) {
            printf("%4d", p->data);    /*���������B�е�ÿ��Ԫ��*/
        }
    }

    printf("\n");
    DelElem2(A, B);                 /*���ڵ�����A�г��ֵ�B��Ԫ��ɾ������A-B*/
    printf("����A�г���B��Ԫ��ɾ����(A-B)������A�е�Ԫ�ػ���%d����\n",
           ListLength(A));

    for (i = 1; i <= ListLength(A); i++) {
        p = Get(A, i);              /*���ص�����A��ÿ������ָ��*/

        if (p) {
            printf("%4d", p->data);    /*��ʾ���ɾ����A������Ԫ��*/
        }
    }

    printf("\n");

}
void DelElem(LinkList A, LinkList B)
/*ɾ��A�г���B��Ԫ�صĺ���ʵ��*/
{
    int i, pos;
    DataType e;
    ListNode* p;

    /*�ڵ�����B�У�ȡ��ÿ��Ԫ���뵥����A�е�Ԫ�رȽϣ���������ɾ��A��Ԫ�ض�Ӧ�Ľ��*/
    for (i = 1; i <= ListLength(B); i++) {
        p = Get(B, i);              /*ȡ��B�е�ÿ����㣬��ָ�뷵�ظ�p*/

        if (p) {
            pos = LocatePos(A, p->data); /*�Ƚ�B�е�Ԫ���Ƿ���A�е�Ԫ�����*/

            if (pos > 0) {
                DeleteList(A, pos, &e);    /*�����ȣ������A��ɾ��*/
            }
        }
    }
}

void DelElem2(LinkList A, LinkList B)
/*ɾ��A�г���B��Ԫ�صĺ���ʵ��*/
{
    ListNode* pre, *p, *r, *q;
    pre = A;
    p = A->next;

    /*�ڵ�����B�У�ȡ��ÿ��Ԫ���뵥����A�е�Ԫ�رȽϣ���������ɾ��A��Ԫ�ض�Ӧ�Ľ��*/
    while (p != NULL) {
        q = B->next;

        while (q != NULL && q->data != p->data) {
            q = q->next;
        }

        if (q != NULL) {
            r = p;
            pre->next = p->next;
            p = r->next;
            free(r);
        } else {
            pre = p;
            p = p->next;
        }
    }
}
