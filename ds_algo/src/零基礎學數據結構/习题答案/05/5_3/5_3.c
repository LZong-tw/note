#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int DataType;
typedef struct QNode { /*�����н�㶨��*/
    DataType data;
    struct QNode* next;
} LQNode, *QueuePtr;
typedef struct { /*��ʽ���еĶ���*/
    QueuePtr rear;/*rearָ������ж�β���*/
} LinkQueue;


void InitQueue(LinkQueue* LQ)
/*��ʽѭ�����еĳ�ʼ��*/
{
    if ((LQ->rear = (LQNode*)malloc(sizeof(LQNode))) ==
        NULL) { /*���������ռ�ʧ���˳�*/
        exit(-1);
    } else {
        LQ->rear->next = LQ->rear;    /*��βָ��ָ��ͷ���*/
    }
}
int QueueEmpty(LinkQueue LQ)
/*�ж���ʽ�����Ƿ�Ϊ�գ�����Ϊ�շ���1�����򷵻�0*/
{
    if (LQ.rear == LQ.rear->next) { /*����ʽ����Ϊ��ʱ������1�����򷵻�0*/
        return 1;
    } else {
        return 0;
    }
}
int EnterQueue(LinkQueue* LQ, DataType e)
/*��Ԫ��e���뵽��ʽ����LQ�У�����ɹ�����1*/
{
    LQNode* s;
    s = (LQNode*)malloc(sizeof(LQNode)); /*Ϊ��Ҫ��ӵ�Ԫ������һ�����Ŀռ�*/

    if (!s) {
        exit(-1);    /*�������ռ�ʧ�ܣ����˳������ز���-1*/
    }

    s->data = e;                        /*��Ԫ��ֵ��ֵ������������*/
    s->next = LQ->rear->next;           /*�����*s���뵽������*/
    LQ->rear->next = s;
    LQ->rear = s;                       /*ʹs��Ϊ�µĶ�β*/
    return 1;
}

int DeleteQueue(LinkQueue* LQ, DataType* e)
/*���Ӳ���*/
{
    LQNode* f, *p;

    if (LQ->rear ==
        LQ->rear->next) { /*��ɾ����ͷԪ�ؼ�������֮ǰ���ж���ʽ�����Ƿ�Ϊ��*/
        return 0;
    } else {
        f = LQ->rear->next;         /*ʹָ��fָ��ͷ���*/
        p = f->next;                /*ʹָ��pָ��Ҫɾ���Ľ��*/

        if (p == LQ->rear) {        /*���������ֻ��һ���������*/
            LQ->rear = LQ->rear->next;  /*ʹָ��rearָ��ͷ���*/
            LQ->rear->next = LQ->rear;
        } else {
            f->next = p->next;    /*ʹͷ���ָ��Ҫ�����е���һ�����*/
        }

        *e = p->data;               /*�Ѷ�ͷԪ��ֵ��ֵ��e*/
        free(p);                    /*�ͷ�ָ��pָ��Ľ��*/
        return 1;
    }
}

void main()
{
    LinkQueue Q;
    DataType a[] = {3, 5, 6, 7, 9, 12}, e;
    int n = 6, i;
    InitQueue(&Q);

    for (i = 0; i < n; i++) {
        EnterQueue(&Q, a[i]);
    }

    printf("����ɾ�������е�Ԫ�أ�");

    while (!QueueEmpty(Q)) {
        DeleteQueue(&Q, &e);
        printf("%4d", e);
    }

    printf("\n");

}