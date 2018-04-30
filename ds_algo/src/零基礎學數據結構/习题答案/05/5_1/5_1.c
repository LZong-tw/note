#define QueueSize 20        /*����˳��ѭ�����е��������*/
typedef int DataType;       /*����˳��ѭ������Ԫ�ص�����Ϊ�ַ�����*/
#include<stdio.h>
typedef struct Squeue {         /*˳��ѭ�����е����Ͷ���*/
    DataType sequ[QueueSize];
    int rear, quelen;       /*��βָ�롢����Ԫ�ظ���*/
} SCQueue;
void InitQueue(SCQueue* SCQ)
/*��ʼ��˳��ѭ������*/
{
    SCQ ->rear = 0; /*�Ѷ�βָ����Ϊ0*/
    SCQ->quelen = 0; /*��ʼʱ������Ԫ�ظ���Ϊ0*/
}
int QueueEmpty(SCQueue SCQ)
/*�ж�˳��ѭ�������Ƿ�Ϊ�գ�����Ϊ�շ���1�����򷵻�0*/
{
    if (SCQ.quelen == 0) {
        return 1;
    } else {
        return 0;
    }
}
int EnterQueue(SCQueue* SCQ, DataType e)
/*��Ԫ��e���뵽˳��ѭ������SCQ�У�����ɹ�����1�����򷵻�0*/
{
    if (SCQ->quelen == QueueSize - 1) {      /*�ж϶����Ƿ�����*/
        return 0;
    }

    SCQ->sequ[SCQ->rear] = e;                /*�ڶ�β����Ԫ��e */
    SCQ->rear = (SCQ->rear + 1) % QueueSize; /*��βָ������ƶ�һ��λ��*/
    SCQ->quelen = SCQ->quelen + 1;           /*�޸Ķ���Ԫ�صĸ���*/
    return 1;
}
int DeleteQueue(SCQueue* SCQ, DataType* e)
/*ɾ��˳��ѭ�������еĶ�ͷԪ�أ�������Ԫ�ظ�ֵ��e��ɾ���ɹ�����1�����򷵻�0*/
{
    int front;

    if (SCQ->quelen == 0) { /*�ж�˳��ѭ�������Ƿ�Ϊ��*/
        return 0;
    } else {
        front = SCQ->rear - SCQ->quelen; /*�����ͷԪ�����ڵ�λ��*/

        if (front < 0) {
            front = front + QueueSize;
        }

        *e = SCQ->sequ[front];          /*����ͷ��Ԫ�ظ�ֵ��e*/
        SCQ->quelen = SCQ->quelen - 1;  /*�޸Ķ����е�Ԫ�ظ���*/
        return 1;
    }
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

    printf("�����е�Ԫ�������ǣ�");

    while (!QueueEmpty(Q)) {
        DeleteQueue(&Q, &e);
        printf("%4d", e);
    }

    printf("\n");
}

