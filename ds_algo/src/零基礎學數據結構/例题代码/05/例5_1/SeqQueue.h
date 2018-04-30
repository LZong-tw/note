typedef struct Squeue { /*˳��������Ͷ���*/
    DataType queue[QueueSize];
    int front, rear; /*��ͷָ��Ͷ�βָ��*/
} SeqQueue;
void InitQueue(SeqQueue* SQ)
/*��˳����г�ʼ��Ϊ�ն���ֻ��Ҫ�Ѷ�ͷָ��Ͷ�βָ��ͬʱ��Ϊ0*/
{
    SQ->front = SQ->rear = 0; /*�Ѷ�ͷָ��Ͷ�βָ��ͬʱ��Ϊ0*/
}
int QueueEmpty(SeqQueue SQ)
/*�ж϶����Ƿ�Ϊ�գ�����Ϊ�շ���1�����򷵻�0*/
{
    if (SQ.front == SQ.rear) {   /*�ж϶�ͷָ��Ͷ�βָ���Ƿ����*/
        return 1;    /*������Ϊ��ʱ������1�����򷵻�0*/
    } else {
        return 0;
    }
}
int EnterQueue(SeqQueue* SQ, DataType x)
/*��Ԫ��x���뵽˳�����SQ�У�����ɹ�����1�����򷵻�0*/
{
    if (SQ->rear ==
        QueueSize) { /*�ڲ����µ�Ԫ��֮ǰ���ж϶�βָ���Ƿ񵽴���������ֵ�����Ƿ��������*/
        return 0;
    }

    SQ->queue[SQ->rear] = x; /*�ڶ�β����Ԫ��x */
    SQ->rear = SQ->rear + 1; /*��βָ������ƶ�һ��λ��*/
    return 1;
}
int DeleteQueue(SeqQueue* SQ, DataType* e)
/*ɾ��˳������еĶ�ͷԪ�أ�������Ԫ�ظ�ֵ��e��ɾ���ɹ�����1�����򷵻�0*/
{
    if (SQ->front == SQ->rear) { /*��ɾ��Ԫ��֮ǰ���ж϶����Ƿ�Ϊ��*/
        return 0;
    } else {
        *e = SQ->queue[SQ->front];  /*��Ҫɾ����Ԫ�ظ�ֵ��e*/
        SQ->front = SQ->front + 1; /*����ͷָ������ƶ�һ��λ�ã�ָ���µĶ�ͷ*/
        return 1;
    }
}
