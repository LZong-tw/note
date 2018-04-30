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
/*��������*/
LinkList CreateCycList(int n);/*����һ������Ϊn��ѭ��������ĺ�������*/
void Josephus(LinkList head, int n, int m,
              int k); /*�ڳ���Ϊn��ѭ���������У�����Ϊ���Ϊm�ĳ���*/
void DisplayCycList(LinkList head);/*���ѭ��������*/
void main()
{

    LinkList h;
    int n, k, m;
    printf("���뻷���˵ĸ���n=");
    scanf("%d", &n);
    printf("���뿪ʼ���������k=");
    scanf("%d", &k);
    printf("����Ϊm���˳���m=");
    scanf("%d", &m);
    h = CreateCycList(n);
    Josephus(h, n, m, k);
}
void Josephus(LinkList head, int n, int m, int k)
/*�ڳ���Ϊn��ѭ���������У��ӵ�k���˿�ʼ����������m���˳���*/
{
    ListNode* p, *q;
    int i;
    p = head;

    for (i = 1; i < k; i++) { /*�ӵ�k���˿�ʼ����*/
        q = p;
        p = p->next;
    }

    while (p->next != p) {
        for (i = 1; i < m; i++) { /*����m���˳���*/
            q = p;
            p = p->next;
        }

        q->next = p->next;  /*��pָ��Ľ��ɾ����������Ϊm���˳���*/
        printf("%4d", p->data);
        free(p);
        p = q->next;        /*pָ����һ����㣬���¿�ʼ����*/
    }

    printf("%4d\n", p->data);
}
LinkList CreateCycList(int n)
/*�궨��͵��������Ͷ���*/
{
    LinkList head = NULL;
    ListNode* s, *r;
    int i;

    for (i = 1; i <= n; i++) {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->data = i;
        s->next = NULL;

        if (head == NULL) {
            head = s;
        } else {
            r->next = s;
        }

        r = s;
    }

    r->next = head;
    return head;
}
void DisplayCycList(LinkList head)
/*���ѭ�������ÿһ��Ԫ��*/
{
    ListNode* p;
    p = head;

    if (p == NULL) {
        printf("�������ǿձ�");
        return;
    }

    while (p->next != head) { /*����������һ����㣬����ý��*/
        printf("%4d", p->data);
        p = p->next;
    }

    printf("%4d\n", p->data); /*������һ�����*/
}
