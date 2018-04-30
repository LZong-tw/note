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
void AddMatrix(CrossList A, CrossList B, CrossList* C);
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
    AddMatrix(M, N, &Q);
    printf("����ϡ�������ӽ����M+N=\n");
    PrintMatrix(Q);
    /*�ھ���M�в���һ��Ԫ��*/
    printf("������Ҫ����Ԫ�ص��кš��кź�Ԫ��ֵ��");
    scanf("%d,%d,%d", &row, &col, &value);
    p = (OLNode*)malloc(sizeof(OLNode));
    p->i = row;
    p->j = col;
    p->e = value;
    InsertMatrix(&M, p);
    printf("����Ԫ�غ󣬾���M��\n");
    PrintMatrix(M);
}

void AddMatrix(CrossList A, CrossList B, CrossList* C)
/*ʮ�������ʾ������ϡ������������*/
{
    int i;
    OLink pa, pb, pc;

    if (A.m != B.m || A.n != B.n) {
        printf("����������ͬ���͵�,�������\n");
        exit(-1);
    }

    /*��ʼ������Q*/
    C->m = A.m;
    C->n = A.n;
    C->len = 0;             /*����C��Ԫ�ظ����ĳ�ֵΪ0*/

    /*��ʼ��ʮ������*/
    if (!(C->rowhead = (OLink*)malloc(C->m * sizeof(
                                          OLink)))) { /*��̬�����б�ͷ����*/
        exit(-1);
    }

    if (!(C->colhead = (OLink*)malloc(C->n * sizeof(
                                          OLink)))) { /*��̬�����б�ͷ����*/
        exit(-1);
    }

    for (i = 0; i < C->m; i++) { /*��ʼ������C���б�ͷָ�����飬��������Ϊ��*/
        C->rowhead[i] = NULL;
    }

    for (i = 0; i < C->n; i++) { /*��ʼ������C���б�ͷָ�����飬��������Ϊ��*/
        C->colhead[i] = NULL;
    }

    /*��ϡ������е�˳�����*/
    for (i = 0; i < A.m; i++) {
        pa = A.rowhead[i];  /*paָ�����A�ĵ�i�еĵ�1�����*/
        pb = B.rowhead[i];  /*pbָ�����B�ĵ�i�еĵ�1�����*/

        while (pa && pb) {
            pc = (OLink)malloc(sizeof(OLNode)); /*�����½��*/

            switch (CompareElement(pa->j, pb->j)) {
            case -1:                /*���A���к�С��B���кţ�������A�ĵ�ǰԪ��ֵ����C*/
                *pc = *pa;
                InsertMatrix(C, pc);
                pa = pa->right;
                break;

            case  0:                /*�������A��B���к���ȣ�Ԫ��ֵ���*/
                *pc = *pa;
                pc->e += pb->e;

                if (pc->e != 0) {   /*�����Ϊ���㣬�򽫽����뵽C��*/
                    InsertMatrix(C, pc);
                } else {
                    free(pc);
                }

                pa = pa->right;
                pb = pb->right;
                break;

            case  1:                /*���A���кŴ���B���кţ�������B�ĵ�ǰԪ��ֵ����C��*/
                *pc = *pb;
                InsertMatrix(C, pc);
                pb = pb->right;
            }
        }

        while (pa) {                /*�������A����δ������ķ���Ԫ�أ���ʣ��Ԫ�ز���C��*/
            pc = (OLink)malloc(sizeof(OLNode));
            *pc = *pa;
            InsertMatrix(C, pc);
            pa = pa->right;
        }

        while (pb) {                /*�������B����δ������ķ���Ԫ�أ���ʣ��Ԫ�ز���C��*/
            pc = (OLink)malloc(sizeof(OLNode));
            *pc = *pb;
            InsertMatrix(C, pc);
            pb = pb->right;
        }
    }

    if (C->len == 0) {              /*����C�ķ���Ԫ�ظ���Ϊ�㣬��ֱ������C*/
        DestroyMatrix(C);
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