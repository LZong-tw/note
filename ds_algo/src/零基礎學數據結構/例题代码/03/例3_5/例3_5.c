/*����ͷ�ļ�*/
#include<stdio.h>
#include<malloc.h>

/*�궨��͵��������Ͷ���*/
#define ListSize 100
typedef int DataType;
typedef struct Node {
    DataType data;
    struct Node* next;
} ListNode, *LinkList;
/*��������*/
LinkList CreateCycList(int n);              /*����һ��ѭ��������ĺ�������*/
void DisplayCycList();                      /*��ʾ���ѭ��������ĺ�������*/
LinkList Link(LinkList head1, LinkList head2); /*��������������һ��ĺ�������*/
void main()
{
    LinkList h1, h2;
    int n;
    printf("����һ��ѭ��������h1��\n");
    printf("������Ԫ�ظ�����\n");
    scanf("%d", &n);
    h1 = CreateCycList(n);
    printf("����һ��ѭ��������h2��\n");
    printf("������Ԫ�ظ�����\n");
    scanf("%d", &n);
    h2 = CreateCycList(n);
    printf("���ѭ��������h1\n");
    DisplayCycList(h1);
    printf("���ѭ��������h2\n");
    DisplayCycList(h2);
    h1 = Link(h1, h2);
    printf("������Ӻ��ѭ��������h1+h2\n");
    DisplayCycList(h1);
}
LinkList Link(LinkList head1, LinkList head2)
/*����������head1��head2������һ���γ�һ��ѭ������*/
{
    ListNode* p, *q;
    p = head1;

    while (p->next != head1) { /*ָ��pָ����������һ�����*/
        p = p->next;
    }

    q = head2;

    while (q->next != head2) { /*ָ��qָ����������һ�����*/
        q = q->next;
    }

    p->next = head2;    /*����һ�������β�����ӵ��ڶ�������ĵ�һ�����*/
    q->next = head1;    /*���ڶ��������β�����ӵ���һ������ĵ�һ�����*/
    return head1;
}
LinkList CreateCycList(int n)
/*����һ������ͷ����ѭ��������*/
{
    DataType e;
    LinkList head = NULL;
    ListNode* p, *q;
    int i;
    i = 1;
    q = NULL;

    while (i <= n) {
        printf("�������%d��Ԫ��.", i);
        scanf("%d", &e);

        if (i == 1) {       /*������һ�����*/
            head = (LinkList)malloc(sizeof(ListNode));
            head->data = e;
            head->next = NULL;
            q = head;       /*ָ��qָ����������һ�����*/
        } else {
            p = (ListNode*)malloc(sizeof(ListNode));
            p->data = e;
            p->next = NULL;
            q->next = p;    /*���½�����ӵ�������*/
            q = p;          /*qʼ��ָ�����һ�����*/
        }

        i++;
    }

    if (q != NULL) {
        q->next = head;    /*�����һ������ָ��ָ��ͷָ�룬ʹ���γ�һ��ѭ������*/
    }

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