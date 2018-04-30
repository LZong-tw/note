

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
void DispList2(SqList L, int pivot, int count);
void DispList3(SqList L, int count);
void HeapSort(SqList* H);
void BubbleSort(SqList* L, int n);
void BubbleSort(SqList* L, int n)
/*ð������*/
{
    int i, j, flag;
    DataType t;
    static int count = 1;

    for (i = 1; i <= n - 1 && flag; i++) { /*��Ҫ����n-1������*/
        flag = 0;

        for (j = 1; j <= n - i; j++) /*ÿһ��������Ҫ�Ƚ�n-i��*/
            if (L->data[j].key > L->data[j + 1].key) {
                t = L->data[j];
                L->data[j] = L->data[j + 1];
                L->data[j + 1] = t;
                flag = 1;
            }

        DispList3(*L, count);
        count++;
    }
}
void QSort(SqList* L, int low, int high)
/*��˳���L���п�������*/
{
    int pivot;
    static count = 1;

    if (low < high) {                       /*���Ԫ�����еĳ��ȴ���1*/
        pivot = Partition(L, low, high);    /*������������L.r[low..high]����Ϊ������*/
        DispList2(*L, pivot, count);        /*���ÿ�λ��ֵĽ��*/
        count++;
        QSort(L, low, pivot -
              1);           /*����ߵ��ӱ���еݹ�����pivot������λ��*/
        QSort(L, pivot + 1, high);          /*���ұߵ��ӱ���еݹ����� */
    }
}

void QuickSort(SqList* L)
/* ��˳���L����������*/
{
    QSort(L, 1, (*L).length);
}

int Partition(SqList* L, int low, int high)
/*��˳���L.r[low..high]��Ԫ�ؽ���һ������ʹ����ǰ���Ԫ�عؼ���С��
����Ԫ�صĹؼ��֣���������Ԫ�عؼ��ִ��ڵ�������Ԫ�صĹؼ��֣�����������λ��*/
{
    DataType t;
    KeyType pivotkey;
    pivotkey = (*L).data[low].key;  /*����ĵ�һ��Ԫ����Ϊ����Ԫ��*/
    t = (*L).data[low];

    while (low < high) {            /*�ӱ�����˽�������м�ɨ��*/
        while (low < high && (*L).data[high].key >= pivotkey) { /*�ӱ��ĩ����ǰɨ��*/
            high--;
        }

        if (low < high) {           /*����ǰhighָ���Ԫ�ر�����lowλ��*/
            (*L).data[low] = (*L).data[high];
            low++;
        }

        while (low < high && (*L).data[low].key <= pivotkey) { /*�ӱ��ʼ�����ɨ��*/
            low++;
        }

        if (low < high) {           /*����ǰlowָ���Ԫ�ر�����highλ��*/
            (*L).data[high] = (*L).data[low];
            high--;
        }

        (*L).data[low] = t;         /*������Ԫ�ر�����low=high��λ��*/

    }

    return low;                     /*������������λ��*/
}

void DispList2(SqList L, int pivot, int count)
{
    int i;
    printf("��%d��������:[", count);

    for (i = 1; i < pivot; i++) {
        printf("%-4d", L.data[i].key);
    }

    printf("]");
    printf("%3d ", L.data[pivot].key);
    printf("[");

    for (i = pivot + 1; i <= L.length; i++) {
        printf("%-4d", L.data[i].key);
    }

    printf("]");
    printf("\n");

}
void DispList3(SqList L, int count)
/*������е�Ԫ��*/
{
    int i;
    printf("��%d��������:", count);

    for (i = 1; i <= L.length; i++) {
        printf("%4d", L.data[i].key);
    }

    printf("\n");
}
void main()
{
    DataType a[] = {37, 22, 43, 32, 19, 12, 89, 26, 48, 92};
    int i, n = 10;
    SqList L;
    /*ð������*/
    InitSeqList(&L, a, n);
    printf("ð������ǰ��");
    DispList(L);
    BubbleSort(&L, n);
    printf("ð����������");
    DispList(L, n);
    /*��������*/
    InitSeqList(&L, a, n);
    printf("��������ǰ��");
    DispList(L, n);
    QuickSort(&L, n);
    printf("������������");
    DispList(L);
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