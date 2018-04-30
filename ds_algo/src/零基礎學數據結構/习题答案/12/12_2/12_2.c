/*����ͷ�ļ�*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int KeyType;
typedef struct { /*����Ԫ�����Ͷ���*/
    KeyType key;/*�ؼ���*/
} DataType;
typedef struct Node {   /*���������Ͷ���*/
    DataType data;
    struct Node* next;
} ListNode, *LinkList;

void SelectSort(LinkList L);
void CreateList(LinkList L, DataType a[], int n);
void BubbleSort(LinkList L);
void CreateList(LinkList L, DataType a[], int n)
/*����������*/
{
    int i;

    for (i = 1; i <= n; i++) {
        InsertList(L, i, a[i - 1]);
    }
}
void InitList(LinkList* head)
/*���������ʼ��Ϊ�ա���̬����һ��ͷ��㣬����ͷ����ָ������Ϊ�ա�*/
{
    if ((*head = (LinkList)malloc(sizeof(ListNode))) ==
        NULL) { /*Ϊͷ������һ���洢�ռ�*/
        exit(-1);
    }

    (*head)->next = NULL;           /*���������ͷ���ָ������Ϊ��*/
}
int InsertList(LinkList head, int i, DataType e)
/*�ڵ������е�i��λ�ò���һ����㣬����Ԫ��ֵΪe������ɹ�����1��ʧ�ܷ���0*/
{
    ListNode* p,
              *pre;  /*����ָ���i��Ԫ�ص�ǰ�����ָ��pre��ָ��pָ�������ɵĽ��*/
    int j;
    pre = head;         /*ָ��pָ��ͷ���*/
    j = 0;

    while (pre->next != NULL &&
           j < i - 1) { /*�ҵ���i��1����㣬����i������ǰ�����*/
        pre = pre->next;
        j++;
    }

    if (!pre) {                 /*���û�ҵ���˵������λ�ô���*/
        printf("����λ�ô�");
        return 0;
    }

    /*������һ����㣬����e��ֵ���ý���������*/
    if ((p = (ListNode*)malloc(sizeof(ListNode))) == NULL) {
        exit(-1);
    }

    p->data = e;
    /*���������*/
    p->next = pre->next;
    pre->next = p;
    return 1;
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
    BubbleSort(L);
    printf("ð�������\n");

    for (p = L->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }

    printf("\n");
}

void BubbleSort(LinkList L)
/*������洢�ṹʵ��ð������*/
{
    ListNode* p, *q, *s;
    s = NULL;               /*ָ��sָ���Ѿ��ź���ĵ�һ�����*/

    while (s != L->next) {  /*������д�����Ԫ�أ�������Ƚ�*/
        q = L;
        p = q->next;        /*���*pΪ�����������еĵ�һ�����*/

        while (p->next != s) { /*����ڸ��������У�����Ԫ����Ҫ�Ƚ�*/
            if (p->data.key > p->next->data.key) { /*������������λ��*/
                q->next = p->next;
                p->next = q->next->next;
                q->next->next = p;
            }

            q = q->next;
            p = q->next;
        }

        s = p;              /*sָ���Ѿ��ź��������ĵ�һ�����*/
    }
}
