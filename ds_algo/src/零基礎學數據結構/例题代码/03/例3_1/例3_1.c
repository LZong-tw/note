#include<stdio.h>                   /*�����������ͷ�ļ�*/
#include"SeqList.h"                 /*����˳���ʵ���ļ�*/
void DelElem(SeqList* A, SeqList B); /*ɾ��A�г���B��Ԫ�صĺ�������*/
void main()
{
    int i, j, flag;
    DataType e;
    SeqList A, B;                   /*����˳���A��B*/
    InitList(&A);                   /*��ʼ��˳���A*/
    InitList(&B);                   /*��ʼ��˳���B*/

    for (i = 1; i <= 10; i++) {     /*��1-10���뵽˳���A��*/
        if (InsertList(&A, i, i) == 0) {
            printf("λ�ò��Ϸ�");
            return;
        }
    }

    for (i = 1, j = 1; j <= 6; i = i + 2, j++) { /*����˳���B��������*/
        if (InsertList(&B, j, i * 2) == 0) {
            printf("λ�ò��Ϸ�");
            return;
        }
    }

    printf("˳���A�е�Ԫ�أ�\n");

    for (i = 1; i <= A.length; i++) { /*���˳���A�е�ÿ��Ԫ��*/
        flag = GetElem(A, i, &e);   /*����˳���A�е�ÿ��Ԫ�ص�e��*/

        if (flag == 1) {
            printf("%4d", e);
        }
    }

    printf("\n");
    printf("˳���B�е�Ԫ�أ�\n");

    for (i = 1; i <= B.length; i++) { /*���˳���B�е�ÿ��Ԫ��*/
        flag = GetElem(B, i, &e);   /*����˳���B�е�ÿ��Ԫ�ص�e��*/

        if (flag == 1) {
            printf("%4d", e);
        }
    }

    printf("\n");
    printf("����A�г���B��Ԫ��ɾ����A�е�Ԫ�أ�\n");
    DelElem(&A, B);                 /*����˳���A�г��ֵ�B��Ԫ��ɾ��*/

    for (i = 1; i <= A.length; i++) { /*��ʾ���ɾ����A������Ԫ��*/
        flag = GetElem(A, i, &e);

        if (flag == 1) {
            printf("%4d", e);
        }
    }

    printf("\n");

}
void DelElem(SeqList* A, SeqList B)
/*ɾ��A�г���B��Ԫ�صĺ���ʵ��*/
{
    int i, flag, pos;
    DataType e;

    for (i = 0; i <= B.length; i++) {
        flag = GetElem(B, i, &e);   /*���ΰ�B��ÿ��Ԫ��ȡ����e*/

        if (flag == 1) {
            pos = LocateElem(*A, e); /*��A�в��Һ�B��ȡ����Ԫ��e��ȵ�Ԫ��*/

            if (pos > 0) {
                DeleteList(A, pos, &e);    /*����ҵ���Ԫ�أ������A��ɾ��*/
            }
        }
    }
}