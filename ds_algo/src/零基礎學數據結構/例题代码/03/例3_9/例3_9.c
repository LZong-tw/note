#include<stdio.h>                   /*�����������ͷ�ļ�*/
#include"SeqList.h"                 /*����˳���ʵ���ļ�*/
void SplitSeqList(SeqList* L);      /*����˳���L*/
void main()
{
    int i, flag, n;
    DataType e;
    SeqList L;
    int a[] = {-7, 0, 5, -8, 9, -4, 3, -2};
    InitList(&L);                   /*��ʼ��˳���L*/
    n = sizeof(a) / sizeof(a[0]);

    for (i = 1; i <= n; i++) {      /*������a��Ԫ�ز��뵽˳���L��*/
        if (InsertList(&L, i, a[i - 1]) == 0) {
            printf("λ�ò��Ϸ�");
            return;
        }
    }

    printf("˳���L�е�Ԫ�أ�\n");

    for (i = 1; i <= L.length; i++) { /*���˳���L�е�ÿ��Ԫ��*/
        flag = GetElem(L, i, &e);   /*����˳���L�е�ÿ��Ԫ�ص�e��*/

        if (flag == 1) {
            printf("%4d", e);
        }
    }

    printf("\n");
    printf("��˳���L���������Ԫ��>=0,�ұ�Ԫ��<0����\n");
    SplitSeqList(&L);                   /*����˳���*/

    for (i = 1; i <= L.length; i++) {   /*���������˳���L������Ԫ��*/
        flag = GetElem(L, i, &e);

        if (flag == 1) {
            printf("%4d", e);
        }
    }

    printf("\n");
}
void SplitSeqList(SeqList* L)
/*����˳���L��ʹԪ�ص�����Ǵ��ڵ���0��Ԫ�أ��ұ���С��0��Ԫ��*/
{
    int i, j;                   /*��������ָʾ��i��j*/
    DataType e;
    i = 0, j = (*L).length - 1; /*ָʾ��i��j�ֱ�ָʾ˳������˺��Ҷ�Ԫ��*/

    while (i < j) {
        while (L->list[i] >= 0) { /*i�������ڵ���0��Ԫ���Թ�*/
            i++;
        }

        while (L->list[j] < 0) { /*j����С��0��Ԫ���Թ�*/
            j--;
        }

        if (i < j) {            /*����Ԫ�ص�i��jָʾ��Ԫ��λ��*/
            e = L->list[i];
            L->list[i] = L->list[j];
            L->list[j] = e;
        }
    }
}