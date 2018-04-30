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
void InsertSort(SqList* L);
void ShellInsert(SqList* L, int c);
void ShellInsertSort(SqList* L, int delta[], int m);
void BinInsertSort(SqList* L);
void DispList(SqList L, int n);
void InsertSort(SqList* L)
/*ֱ�Ӳ�������*/
{
    int i, j;
    DataType t;

    for (i = 1; i < L->length;
         i++) { /*ǰi��Ԫ���Ѿ����򣬴ӵ�i+1��Ԫ�ؿ�ʼ��ǰi��������Ĺؼ��ֱȽ�*/
        t = L->data[i + 1];         /*ȡ����ǰ�������Ԫ��*/
        j = i;

        while (j > -1 && t.key < L->data[j].key) { /*Ѱ�ҵ�ǰԪ�صĺ���λ��*/
            L->data[j + 1] = L->data[j];
            j--;
        }

        L->data[j + 1] = t;         /*����ǰԪ�ز�����ʵ�λ��*/
    }
}
void BinInsertSort(SqList* L)
/*�۰��������*/
{
    int i, j, mid, low, high;
    DataType t;

    for (i = 1; i < L->length;
         i++) { /*ǰi��Ԫ���Ѿ����򣬴ӵ�i+1��Ԫ�ؿ�ʼ��ǰi��������Ĺؼ��ֱȽ�*/
        t = L->data[i + 1];         /*ȡ����i+1��Ԫ�أ����������Ԫ��*/
        low = 1, high = i;

        while (low <= high) {       /*�����۰����˼��Ѱ�ҵ�ǰԪ�صĺ���λ��*/
            mid = (low + high) / 2;

            if (L->data[mid].key > t.key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        for (j = i; j >= low; j--) { /*�ƶ�Ԫ�أ��ճ�Ҫ�����λ��*/
            L->data[j + 1] = L->data[j];
        }

        L->data[low] = t;       /*����ǰԪ�ز�����ʵ�λ��*/
    }
}
void ShellInsert(SqList* L, int c)
/*��˳���L����һ��ϣ������delta������*/
{
    int i, j;
    DataType t;

    for (i = c + 1; i <= L->length;
         i++) { /*������Ϊdelta��Ԫ����Ϊһ�������н�������*/
        if (L->data[i].key < L->data[i - c].key) { /*�������С��ǰ�ߣ�����Ҫ�ƶ�Ԫ��*/
            t = L->data[i];

            for (j = i - c; j > 0 && t.key < L->data[j].key; j = j - c) {
                L->data[j + c] = L->data[j];
            }

            L->data[j + c] = t;             /*���ν�Ԫ�ز��뵽��ȷ��λ��*/
        }
    }
}
void ShellInsertSort(SqList* L, int delta[], int m)
/*ϣ������ÿ�ε����㷨ShellInsert,delta�Ǵ������������*/
{
    int i;

    for (i = 0; i < m; i++) { /*����m��ϣ����������*/
        ShellInsert(L, delta[i]);
    }
}
void main()
{
    DataType a[] = {56, 22, 67, 32, 59, 12, 89, 26, 48, 37};
    int delta[] = {5, 3, 1};
    int i, n = 10, m = 3;
    SqList L;
    /*ֱ�Ӳ�������*/
    InitSeqList(&L, a, n);
    printf("����ǰ��");
    DispList(L, n);
    InsertSort(&L);
    printf("ֱ�Ӳ�����������");
    DispList(L, n);
    /*�۰��������*/
    InitSeqList(&L, a, n);
    printf("����ǰ��");
    DispList(L, n);
    BinInsertSort(&L);
    printf("�۰������������");
    DispList(L, n);
    /*ϣ������*/
    InitSeqList(&L, a, n);
    printf("����ǰ��");
    DispList(L, n);
    ShellInsertSort(&L, delta, m);
    printf("ϣ����������");
    DispList(L, n);
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
void DispList(SqList L, int n)
/*������е�Ԫ��*/
{
    int i;

    for (i = 1; i <= n; i++) {
        printf("%4d", L.data[i].key);
    }

    printf("\n");
}