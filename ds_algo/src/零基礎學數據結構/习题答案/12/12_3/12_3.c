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
void Split(SqList* L, int low, int high, int* i);
void QuickSort(SqList* L)
/*����ջʵ�ֿ�������(�ǵݹ�)*/
{
    int i = 1, j = 1, k = 1;
    int stack[MaxSize][2], top = -1;
    int low = 1, high = L->length;
    top++;
    stack[top][0] = low;
    stack[top][1] = high;

    while (top >= 0) {
        low = stack[top][0];    /*�������ʼλ�ó�ջ��Ȼ�󽫵�ǰ����зָ�Ϊ������С���ӱ�*/
        high = stack[top][1];
        top--;
        Split(L, low, high, &i); /*����ָ�Ϊ��������(����)�������ָ�㷵��*/

        if (low < high) {       /*�������ʼλ�ñ��浽ջ��*/
            top++;
            stack[top][0] = low;
            stack[top][1] = i - 1;
            top++;
            stack[top][0] = i + 1;
            stack[top][1] = high;
        }
    }
}
void Split(SqList* L, int low, int high, int* i)
/*��˳���L.r[low..high]��Ԫ�ؽ���һ������,��L->data[i].key����ָ�Ϊ��������*/
{
    DataType t;
    int j;
    *i = low;
    j = high;
    t = (*L).data[*i];

    while (*i < j) {            /*�ӱ�����˽�������м�ɨ��*/
        while (*i < j && (*L).data[j].key >= t.key) { /*�ӱ��ĩ����ǰɨ��*/
            j--;
        }

        if (*i < j) {           /*����ǰjָ���Ԫ�ر�����iλ��*/
            (*L).data[*i] = (*L).data[j];
            (*i)++;
        }

        while (*i < j && (*L).data[*i].key <= t.key) { /*�ӱ��ʼ�����ɨ��*/
            (*i)++;
        }

        if (*i < j) {           /*����ǰiָ���Ԫ�ر�����jλ��*/
            (*L).data[j] = (*L).data[*i];
            j--;
        }

    }

    (*L).data[*i] = t;

}
void main()
{
    DataType a[] = {41, 32, 34, 5, 12, 43, 67, 98, 21, 73};
    int n = 10;
    SqList L;
    InitSeqList(&L, a, n);
    printf("����ǰL��Ԫ�أ�");
    DispList(L);
    QuickSort(&L);
    printf("�ǵݹ���������L��Ԫ�أ�");
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