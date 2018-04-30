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
void InitSeqList(SqList* L, DataType a[], int start, int n);
void DispList(SqList L);
void Merge(DataType s[], DataType t[], int low, int mid, int high);
void Merge(DataType s[], DataType t[], int low, int mid, int high);

void Merge(DataType s[], DataType t[], int low, int mid, int high)
/*�������s[low...mid]��s[mid+1..high]�鲢Ϊ�����t[low..high]*/
{
    int i, j, k;
    i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) { /*��s��Ԫ����С����غϲ���t*/
        if (s[i].key <= s[j].key) {
            t[k] = s[i++];
        } else {
            t[k] = s[j++];
        }

        k++;
    }

    while (i <= mid) {      /*��ʣ���s[i..mid]���Ƶ�t*/
        t[k++] = s[i++];
    }

    while (j <= high) {     /*��ʣ���s[j..high]���Ƶ�t*/
        t[k++] = s[j++];
    }
}

void MergeSort(DataType s[], DataType t[], int low, int high)
/*2·�鲢���򣬽�s[low...high]�鲢���򲢴洢��t[low...high]��*/
{
    int mid;
    DataType t2[MaxSize];

    if (low == high) {
        t[low] = s[low];
    } else {
        mid = (low + high) /
              2;     /*��s[low...high]ƽ��Ϊs[low...mid]��s[mid+1...high]*/
        MergeSort(s, t2, low, mid); /*��s[low...mid]�鲢Ϊ�����t2[low...mid]*/
        MergeSort(s, t2, mid + 1,
                  high); /*��s[mid+1...high]�鲢Ϊ�����t2[mid+1...high]*/
        Merge(t2, t, low, mid,
              high); /*��t2[low...mid]��t2[mid+1..high]�鲢��t[low...high]*/
    }
}


void main()
{
    DataType a[] = {37, 22, 43, 32, 19, 12, 89, 26, 48, 92};
    DataType b[MaxSize];
    int i, n = 10;
    SqList L;
    /*�鲢����*/
    InitSeqList(&L, a, 0, n); /*������a[0...n-1]��ʼ��Ϊ˳���L*/
    printf("�鲢����ǰ��");
    DispList(L);
    MergeSort(L.data, b, 1, n);
    InitSeqList(&L, b, 1, n); /*������b[1...n]��ʼ��Ϊ˳���L*/
    printf("�鲢��������");
    DispList(L);

}
void InitSeqList(SqList* L, DataType a[], int start, int n)
/*˳���ĳ�ʼ��*/
{
    int i, k;

    for (k = 1, i = start; i < start + n; i++, k++) {
        L->data[k] = a[i];
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
