#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
/*�궨��͵��������Ͷ���*/
typedef int DataType;
typedef struct Node { /*�������Ͷ���*/
    DataType data;
    struct Node* next;
} ListNode, *LinkList;
#include"LinkList.h"                    /*����������ʵ���ļ�*/
void DisplayList(LinkList L);
void ReverseList(LinkList H);
void main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    LinkList L;
    InitList(&L);                           /*��ʼ��������L*/

    for (i = 1; i <= sizeof(a) / sizeof(a[0]);
         i++) { /*������a��Ԫ�ز��뵽������L��*/
        if (InsertList(L, i, a[i - 1]) == 0) {
            printf("λ�ò��Ϸ�");
            return;
        }
    }

    printf("����ǰ�����е�Ԫ�أ�\n");
    DisplayList(L);
    ReverseList(L);
    printf("���ú������е�Ԫ�أ�\n");
    DisplayList(L);

}
void ReverseList(LinkList H)
/*��������*/
{
    ListNode* p, *q;
    p = H->next;    /*pָ������ĵ�һ�����*/
    H->next = NULL;

    while (p) {     /*����ͷ�巨��������β��뵽�����ͷ��*/
        q = p->next;
        p->next = H->next;
        H->next = p;
        p = q;
    }
}
void DisplayList(LinkList L)
/*�������*/
{
    int i;
    ListNode* p;

    for (i = 1; i <= ListLength(L); i++) { /*���������L�е�ÿ��Ԫ��*/
        p = Get(L, i);              /*���ص�����L�е�ÿ������ָ��*/

        if (p) {
            printf("%4d", p->data);    /*���������L�е�ÿ��Ԫ��*/
        }
    }

    printf("\n");
}