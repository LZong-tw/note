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
void MergeList(LinkList A, LinkList B,
               LinkList* C); /*��������A��B��Ԫ�غϲ���C�еĺ�������*/

void main()
{
    int i;
    DataType a[] = {6, 7, 9, 14, 37, 45, 65, 67};
    DataType b[] = {3, 7, 11, 34, 45, 89};

    LinkList A, B, C;               /*����������A��B*/
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
    MergeList(A, B, &C);                /*��������A��B�е�Ԫ�غϲ���C��*/
    printf("��������A��B��Ԫ�غϲ���C�к�C�е�Ԫ����%d����\n", ListLength(C));

    for (i = 1; i <= ListLength(C); i++) {
        p = Get(C, i);              /*���ص�����C��ÿ������ָ��*/

        if (p) {
            printf("%4d", p->data);    /*��ʾ���C������Ԫ��*/
        }
    }

    printf("\n");

}
void MergeList(LinkList A, LinkList B, LinkList* C)
/*������A��B�е�Ԫ�طǵݼ����У���������A��B�е�Ԫ�غϲ���C�У�C�е�Ԫ���԰��շǵݼ�����*/
{
    ListNode* pa, *pb, *pc; /*����ָ������A��B,C��ָ��*/
    pa = A->next;
    pb = B->next;
    *C = A;             /*��������A��ͷ�����ΪC��ͷ���*/
    (*C)->next = NULL;
    pc = *C;

    /*���ν�����A��B�н�С��Ԫ�ش�������C��*/
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next =
                pa;  /*���A�е�Ԫ��С�ڻ����B�е�Ԫ�أ���A�е�Ԫ�صĽ����ΪC�Ľ��*/
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;  /*���A�е�Ԫ�ش���B�е�Ԫ�أ���B�е�Ԫ�صĽ����ΪC�Ľ��*/
            pc = pb;
            pb = pb->next;
        }
    }

    pc->next = pa ? pa : pb; /*��ʣ��Ľ�����C��*/
    free(B);                /*�ͷ�B��ͷ���*/
}

