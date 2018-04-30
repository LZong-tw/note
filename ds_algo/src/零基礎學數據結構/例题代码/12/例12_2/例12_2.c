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
void DispList(SqList L, int n);
void AdjustHeap(SqList* H, int s, int m);
void CreateHeap(SqList* H, int n);
void HeapSort(SqList* H);
void SelectSort(SqList* L, int n);

void SelectSort(SqList* L, int n)
/*��ѡ������*/
{
    int i, j, k;
    DataType t;

    /*����i��Ԫ�صĹؼ��������[i+1...n]��Ԫ�صĹؼ��ֱȽϣ����ؼ�����С�ĵ�Ԫ�ط��ڵ�i��λ��*/
    for (i = 1; i <= n - 1; i++) {
        j = i;

        for (k = i + 1; k <= n; k++) /*�ؼ�����С��Ԫ�ص����Ϊj*/
            if (L->data[k].key < L->data[j].key) {
                j = k;
            }

        if (j != i) {       /*������i������j������Ҫ�����i�����j��Ԫ�ؽ���*/
            t = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = t;
        }
    }
}
void CreateHeap(SqList* H, int n)
/*�����󶥶�*/
{
    int i;

    for (i = n / 2; i >= 1; i--) { /*�����n/2��ʼ�����󶥶�*/
        AdjustHeap(H, i, n);
    }
}
void AdjustHeap(SqList* H, int s, int m)
/*����H.data[s...m]�Ĺؼ��֣�ʹ���Ϊһ���󶥶�*/
{
    DataType t;
    int j;
    t = (*H).data[s];                       /*���������ʱ������t��*/

    for (j = 2 * s; j <= m; j *= 2) {
        if (j < m &&
            (*H).data[j].key < (*H).data[j + 1].key) { /*�عؼ��ֽϴ�ĺ��ӽ������ɸѡ*/
            j++;    /*jΪ�ؼ��ֽϴ�Ľ����±�*/
        }

        if (t.key >
            (*H).data[j].key) { /*������ӽ���ֵС�ڸ�����ֵ���򲻽��н���*/
            break;
        }

        (*H).data[s] = (*H).data[j];
        s = j;
    }

    (*H).data[s] = t;                               /*���������뵽��ȷλ��*/
}

void HeapSort(SqList* H)
/*��˳���H���ж�����*/
{
    DataType t;
    int i;
    CreateHeap(H, H->length);   /*������*/

    for (i = (*H).length; i > 1; i--) { /*���Ѷ�Ԫ�������һ��Ԫ�ؽ��������µ�����*/
        t = (*H).data[1];
        (*H).data[1] = (*H).data[i];
        (*H).data[i] = t;
        AdjustHeap(H, 1, i - 1); /*��(*H).data[1..i-1]����Ϊ�󶥶�*/
    }
}

void main()
{
    DataType a[] = {56, 22, 67, 32, 59, 12, 89, 26, 48, 37};
    int delta[] = {5, 3, 1};
    int i, n = 10, m = 3;
    SqList L;
    /*��ѡ������*/
    InitSeqList(&L, a, n);
    printf("����ǰ��");
    DispList(L, n);
    SelectSort(&L, n);
    printf("��ѡ����������");
    DispList(L, n);
    /*������*/
    InitSeqList(&L, a, n);
    printf("����ǰ��");
    DispList(L, n);
    HeapSort(&L, n);
    printf("����������");
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