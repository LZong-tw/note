#include<stdio.h>
#include"SeqList.h"

void CombAB(SeqList* A, SeqList B)
/*�ϲ�˳���A��B����B�е�Ԫ�ز��뵽A�У�ʹA��Ȼ�ǵ��������˳���*/
{
    int la = A->length, lb = B.length, i = 0;

    while (i < lb) { /*��B�����һ��Ԫ����ǰ��A�е�Ԫ�ص�һ��Ԫ�������бȽ�*/
        if (la == 0 ||
            A->list[la - 1] <
            B.list[i]) { /*���A�е�Ԫ��С��B�е�Ԫ�أ���B���뵽A����ȷ��λ��*/
            A->list[la + lb - i - 1] = B.list[i];
            i++;
        } else {                /*���A�е�Ԫ�ش���B�е�Ԫ�أ���A��Ԫ�غ��Ƹ���Ȼ������Ƚ�*/
            A->list[la + lb - i - 1] = A->list[la - 1];
            la--;
        }
    }

    A->length = A->length + B.length; /*�޸�A�ĳ���*/
}
void main()
{
    SeqList A, B;
    int i, m, n;
    DataType a[] = {3, 7, 8, 12, 15};
    DataType b[] = {9, 5, 4, 1}, e;
    n = 5, m = 4;
    InitList(&A);
    InitList(&B);

    for (i = 0; i < n; i++) {
        InsertList(&A, i + 1, a[i]);
    }

    for (i = 0; i < m; i++) {
        InsertList(&B, i + 1, b[i]);
    }

    printf("˳���A��Ԫ������Ϊ��");

    for (i = 0; i < A.length; i++) {
        GetElem(A, i + 1, &e);
        printf("%4d", e);
    }

    printf("\n");
    printf("˳���B��Ԫ������Ϊ��");

    for (i = 0; i < B.length; i++) {
        GetElem(B, i + 1, &e);
        printf("%4d", e);
    }

    printf("\n");
    CombAB(&A, B);
    printf("˳���A��˳���B�ϲ���A�е�Ԫ������Ϊ��");

    for (i = 0; i < A.length; i++) {
        GetElem(A, i + 1, &e);
        printf("%4d", e);
    }

    printf("\n");
}
