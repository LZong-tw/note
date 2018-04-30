#define QueueSize 50    /*������е��������*/
typedef char DataType;  /*�������Ԫ�ص�����Ϊ�ַ�����*/
#include<stdio.h>       /*����ͷ�ļ�����Ҫ���������������*/
#include"SeqQueue.h"    /*����˳����е�ʵ���㷨�ļ�*/

void main()
{
    SeqQueue Q;
    char str[] = "ABCDEFGH"; /*���彫Ҫ������е��ַ���*/
    int i, length = 8;      /*������е�Ԫ�ظ���*/
    char x;
    InitQueue(&Q);          /*��ʼ��˳�����*/

    for (i = 0; i < length; i++) {
        EnterQueue(&Q, str[i]); /*���ַ����β��뵽˳�������*/
    }

    DeleteQueue(&Q, &x);    /*����ͷԪ�س�����*/
    printf("�����е�Ԫ��Ϊ:%c\n", x);   /*��ʾ��������е�Ԫ��*/
    printf("˳������е�Ԫ��Ϊ:");

    if (!QueueEmpty(Q)) {           /*�ж϶����Ƿ�Ϊ�ն���*/
        for (i = Q.front; i < Q.rear;
             i++) { /*�����ͷָ�뵽��βָ��֮���Ԫ�أ�����������Ԫ��*/
            printf("%c", Q.queue[i]);
        }

    }

    printf("\n");
}
