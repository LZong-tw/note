/*����ͷ�ļ�*/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef int KeyType;
typedef struct { /*����Ԫ�����Ͷ���*/
    KeyType key;/*�ؼ���*/
} DataType;
typedef struct { /*˳������Ͷ���*/
    DataType data[MaxSize];
    int length;
} SqList;
void InitSeqList(SqList* L, DataType a[], int n);
void DispList(SqList L);
void Sort(SqList A, SqList B, SqList* C)
/*�������˳���A��B�ϲ����ϲ��󱣴���C�У���ʹ���������*/
{
    int i = 1, j = 1, k = 1;
    C->length = A.length + B.length;

    while (i <= A.length && j <= B.length) {
        if (A.data[i].key <=
            B.data[j].key) { /*���A��Ԫ�صĹؼ���С�ڵ���B�еĹؼ��֣���A�е�Ԫ�ش��뵽C��*/
            C->data[k] = A.data[i];
            i++;
        } else {                        /*���A��Ԫ�صĹؼ��ִ��ڵ���B�еĹؼ��֣���B�е�Ԫ�ش��뵽C��*/
            C->data[k] = B.data[j];
            j++;
        }

        k++;
    }

    while (i <= A.length) {     /*��A��ʣ��Ԫ�ش��뵽C��*/
        C->data[k] = A.data[i];
        k++;
        i++;
    }

    while (j <= B.length) {     /*��B��ʣ��Ԫ�ش��뵽C��*/
        C->data[k] = B.data[j];
        k++;
        j++;
    }
}

void main()
{
    DataType a[] = {4, 8, 34, 56, 89, 103};
    DataType b[] = {23, 45, 78, 90};
    int n = 6, m = 4;
    SqList A, B, C;
    InitSeqList(&A, a, n);
    InitSeqList(&B, b, m);
    printf("����ǰA��Ԫ�أ�");
    DispList(A);
    printf("����ǰB��Ԫ�أ�");
    DispList(B);
    Sort(A, B, &C);
    printf("��A��B�ϲ���C�е�Ԫ�أ�");
    DispList(C);
}
void InitSeqList(SqList* L, DataType a[], int n)
/*˳���ĳ�ʼ��*/
{
    int i;

    for (i = 1; i <= n; i++) {
        L->data[i] = a[i - 1];
    }

    L->length = n;

}
void DispList(SqList L)
/*������е�Ԫ��*/
{
    int i;

    for (i = 1; i <= L.length; i++) {
        printf("%4d", L.data[i].key);
    }

    printf("\n");
}