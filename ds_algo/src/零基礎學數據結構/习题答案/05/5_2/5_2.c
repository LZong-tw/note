#define QueueSize 20        /*����˳��ѭ�����е��������*/
typedef int DataType;       /*����˳��ѭ������Ԫ�ص�����Ϊ�ַ�����*/
#include<stdio.h>
typedef struct Squeue {         /*˳��ѭ�����е����Ͷ���*/
    DataType queue[QueueSize];
    int front, rear;        /*��ͷָ��Ͷ�βָ��*/
} SCQueue;
void InitQueue(SCQueue* SCQ)
/*��˳��ѭ�����г�ʼ��Ϊ�ն���ֻ��Ҫ�Ѷ�ͷָ��Ͷ�βָ��ͬʱ��Ϊ0*/
{
    SCQ ->rear = 0;
    SCQ->front = 0;
}
int QueueEmpty(SCQueue SCQ)
/*�ж�˳��ѭ�������Ƿ�Ϊ�գ�����Ϊ�շ���1�����򷵻�0*/
{
    if (SCQ.front == SCQ.rear) { /*��˳��ѭ������Ϊ��ʱ������1�����򷵻�0*/
        return 1;
    } else {
        return 0;
    }
}

int EnterQueue(SCQueue* SCQ, DataType e)
/*��Ԫ��e���뵽˳��ѭ������SCQ�У�����ɹ�����1�����򷵻�0*/
{
    if (SCQ->front == (SCQ->rear + 1) % QueueSize) {
        return 0;
    }

    SCQ->queue[SCQ->rear] = e;               /*�ڶ�β����Ԫ��e */
    SCQ->rear = (SCQ->rear + 1) % QueueSize; /*�ƶ���βָ��*/
    return 1;
}

int DeleteQueue(SCQueue* SCQ, DataType* e)
/*ɾ��˳��ѭ�������еĶ�ͷԪ�أ�������Ԫ�ظ�ֵ��e��ɾ���ɹ�����1�����򷵻�0*/
{
    if (SCQ->front ==
        SCQ->rear) {              /*��ɾ��Ԫ��֮ǰ���ж�˳��ѭ�������Ƿ�Ϊ��*/
        return 0;
    } else {
        *e = SCQ->queue[SCQ->front];            /*��Ҫɾ����Ԫ�ظ�ֵ��e*/
        SCQ->front = (SCQ->front + 1) % QueueSize; /*�ƶ���ͷָ��*/
        return 1;
    }
}

/*------------���ζ�����Ԫ�صĸ���-------------------*/
int ComputeCount(SCQueue SCQ)
{
    int count;
    count = (SCQ.rear - SCQ.front + QueueSize) % QueueSize;
    return count;
}
void main()
{
    SCQueue Q;
    int i, n = 10;
    DataType a[] = {34, 3, 56, 43, 21, 51, 46, 89, 98, 76}, e;
    InitQueue(&Q);

    for (i = 0; i < n; i++) {
        EnterQueue(&Q, a[i]);
    }

    printf("�����е�Ԫ�ظ����ǣ�%2d\n", ComputeCount(Q));
    printf("�����е�Ԫ�������ǣ�");

    for (i = 0; i < n; i++) {
        DeleteQueue(&Q, &e);
        printf("%4d", e);
    }

    printf("\n");
    printf("��ն��к󣬶����е�Ԫ�ظ����ǣ�%2d\n", ComputeCount(Q));
}

