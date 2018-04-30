
#include<stdio.h>
#define MaxSize 200
typedef int DataType;
typedef struct {        /*��Ԫ�����Ͷ���*/
    int i, j;
    DataType e;
} Triple;
typedef struct {        /*�������Ͷ���*/
    Triple data[MaxSize];
    int m, n, len;      /*����������������ͷ���Ԫ�صĸ���*/
} TriSeqMatrix;

void PrintMatrix(TriSeqMatrix M)
/*ϡ���������*/
{
    int n;
    printf("ϡ�����%d��%d�У���%d������Ԫ�ء�\n", M.m, M.n, M.len);
    printf("��  ��  Ԫ��ֵ\n");

    for (n = 0; n < M.len; n++) {
        printf("%2d%4d%8d\n", M.data[n].i, M.data[n].j, M.data[n].e);
    }
}

void main()
{
    TriSeqMatrix M = {{{1, 1, 4}, {2, 3, 4}, {3, 2, 16}, {4, 3, 26}}, 4, 4, 4}; /*ϡ�����ĳ�ʼ��*/
    PrintMatrix(M);                                             /*���ϡ�����*/
}