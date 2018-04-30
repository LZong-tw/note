/*����ͷ�ļ�*/
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
/*ϡ��������Ͷ���*/
typedef int DataType;
typedef struct OLNode {
    int i, j;
    DataType e;
    struct OLNode* right, *down;
} OLNode, *OLink;
typedef struct {
    OLink* rowhead, *colhead;
    int m, n, len;
} CrossList;

#include"CrossMatrix.h"
void MultMatrix(CrossList A, CrossList B, CrossList* C);
int CompareElement(int a, int b);

void main()
{
    CrossList M, N, Q;
    int row, col;
    DataType value;
    OLink p;
    InitMatrix(&M);     /*��ʼ��ϡ�����*/
    CreateMatrix(&M);   /*����ϡ�����*/
    printf("����M��\n");
    PrintMatrix(M);     /*�Ծ������ʽ���ϡ�����*/

    InitMatrix(&N);     /*��ʼ��ϡ�����*/
    CreateMatrix(&N);   /*����ϡ�����*/
    printf("����N��\n");
    PrintMatrix(N); /*�Ծ������ʽ���ϡ�����*/
    /*������������*/
    MultMatrix(M, N, &Q);
    printf("����ϡ�������˽����M+N=\n");
    PrintMatrix(Q);
}

void MultMatrix(CrossList M, CrossList N, CrossList* Q)
/*��ϡ�����M��N�ĵĳ˻�Q=M��N*/
{
    int i, j, e;
    OLink pq, pm, pn;
    InitMatrix(Q);
    Q->m = M.m;
    Q->n = N.n;
    Q->len = 0;
    /*��ʼ��Q�ı�ͷָ������*/
    Q->rowhead = (OLink*)malloc(Q->m * sizeof(OLink)); /*�����б�ͷָ������*/

    if (!M.rowhead) {
        exit(-1);
    }

    Q->colhead = (OLink*)malloc(Q->n * sizeof(OLink)); /*�����б�ͷָ������*/

    if (!M.colhead) {
        exit(-1);
    }

    for (i = 0; i < Q->m; i++) { /*��ʼ������Q���б�ͷָ������������������Ϊ��*/
        Q->rowhead[i] = NULL;
    }

    for (i = 0; i < Q->n; i++) { /*��ʼ������Q���б�ͷָ������������������Ϊ��*/
        Q->colhead[i] = NULL;
    }

    /*������������*/
    for (i = 0; i < Q->m; i++)
        for (j = 0; j < Q->n; j++) {
            pm = M.rowhead[i];
            pn = N.colhead[j];
            e = 0;

            while (pm && pn)
                switch (CompareElement(pn->i, pm->j)) {
                case -1:
                    pn = pn->down; /*��ָ�����*/
                    break;

                case 0:
                    e += pm->e * pn->e;
                    pn = pn->down; /*����ָ�������*/
                    pm = pm->right;
                    break;

                case 1:
                    pm = pm->right; /*��ָ�����*/
                }

            if (e) {             /*�����˽����Ϊ0���򽫸�ֵ���뵽Q��*/
                pq = (OLink)malloc(sizeof(OLNode));

                if (!pq) {
                    exit(-1);
                }

                pq->i = i;
                pq->j = j;
                pq->e = e;
                InsertMatrix(Q, pq); /*�����pq������ֵ����嵽����Q��*/
            }
        }

    if (Q->len == 0) {       /*���Q����Ԫ�ظ���Ϊ0�������پ���*/
        DestroyMatrix(Q);
    }
}
int CompareElement(int a, int b)
/*�Ƚ�����Ԫ��ֵ�Ĵ�С�����a>b������1��a=b���򷵻�0��a<b���򷵻�-1*/
{
    if (a < b) {
        return -1;
    }

    if (a == b) {
        return 0;
    }

    return 1;
}
