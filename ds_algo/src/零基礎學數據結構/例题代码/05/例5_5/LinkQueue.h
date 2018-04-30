
typedef struct QNode {
    DataType data;
    struct QNode* next;
} LQNode, *QueuePtr;
typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;


void InitQueue(LinkQueue* LQ)
/*����ͷ������ʽ���г�ʼ��Ϊ�ն�����Ҫ��ͷ����ָ������Ϊ0*/
{
    LQ->front = (LQNode*)malloc(sizeof(LQNode));

    if (LQ->front == NULL) {
        exit(-1);
    }

    LQ ->front->next = NULL; /*��ͷ����ָ������ΪΪ0*/
    LQ->rear = LQ->front;
}
int QueueEmpty(LinkQueue LQ)
/*�ж���ʽ�����Ƿ�Ϊ�գ�����Ϊ�շ���1�����򷵻�0*/
{
    if (LQ.front->next == NULL) {   /*����ʽ����Ϊ��ʱ������1�����򷵻�0*/
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
    s->next = NULL;                     /*������ָ������Ϊ��*/
    LQ->rear->next = s;                 /*��ԭ�����еĶ�βָ��ָ��p*/
    LQ->rear = s;                   /*����βָ��ָ��p*/
    return 1;
}
//int DeleteQueue(LinkQueue *LQ,DataType *e)
///*ɾ����ʽ�����еĶ�ͷԪ�أ�������Ԫ�ظ�ֵ��e��ɾ���ɹ�����1�����򷵻�0*/
//{
//    LQNode *s;
//if(LQ->front==LQ->rear)       /*��ɾ��Ԫ��֮ǰ���ж���ʽ�����Ƿ�Ϊ��*/
//        return 0;
//    else
//{
//    s=LQ->front->next;                /*ʹָ��pָ���ͷԪ�ص�ָ��*/
//    *e=s->data;                       /*��Ҫɾ���Ķ�ͷԪ�ظ�ֵ��e*/
//    LQ->front->next=s->next;          /*ʹͷ����ָ��ָ��ָ��p����һ�����*/
//    if(LQ->rear==s) LQ->rear=LQ->front;   /*���Ҫɾ���Ľ���Ƕ�β����ʹ��βָ��ָ���ͷָ��*/
//    free(s);                      /*�ͷ�ָ��pָ��Ľ��*/
//        return 1;
//    }
//}
int GetHead(LinkQueue LQ, DataType* e)
/*ȡ��ʽ�����еĶ�ͷԪ�أ�������Ԫ�ظ�ֵ��e��ȡԪ�سɹ�����1�����򷵻�0*/
{
    LQNode* s;

    if (LQ.front == LQ.rear) {  /*��ȡ��ͷԪ��֮ǰ���ж���ʽ�����Ƿ�Ϊ��*/
        return 0;
    } else {
        s = LQ.front->next; /*��ָ��pָ����еĵ�һ��Ԫ�ؼ���ͷԪ��*/
        *e = s->data;       /*����ͷԪ�ظ�ֵ��e��ȡ����ͷԪ��*/
        return 1;
    }
}
/*���Ӳ�����*/
int DeleteQueue(LinkQueue* Q, DataType* x)
{
    /* ������Q�Ķ�ͷԪ�س��ӣ�����ŵ�x��ָ�Ĵ洢�ռ��� */
    LQNode* p;

    if (Q->front == Q->rear) {
        return (0);
    }

    p = Q->front->next;
    Q->front->next = p->next; /* ��ͷԪ��p���� */

    if (Q->front == NULL) { /* �������ֻ��һ��Ԫ��p����p���Ӻ��Ϊ�ն� */
        Q->rear = Q->front;
    }

    *x = p->data;
    free(p);   /* �ͷŴ洢�ռ� */
    return (1);
}