/*����ͷ�ļ�*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdarg.h>  /*��׼ͷ�ļ�������va_start��va-arg��va_end�궨��*/
typedef int DataType;
#include"SeqArray.h"
void main()
{
    Array A;
    DataType B[4][3] = {{5, 6, 7}, {23, 45, 67}, {35, 2, 34}, {12, 36, 90}};
    int i, j;
    int dim = 2, bound1 = 4, bound2 = 3;    /*��ʼ�������ά���͸�ά�ĳ���*/
    DataType e;
    InitArray(&A, dim, bound1, bound2);     /*����һ��4��3�Ķ�ά����A*/
    printf("����A�ĸ�ά�ĳ�����:");

    for (i = 0; i < dim; i++) {             /*�������A�ĸ�ά�ĳ���*/
        printf("%3d", A.bounds[i]);
    }

    printf("\n����A�ĳ�����ַ��:");

    for (i = 0; i < dim; i++) {             /*�������A�ĳ�����ַ*/
        printf("%3d", A.constants[i]);
    }

    printf("\n%d��%d�еľ���Ԫ������:\n", bound1, bound2);

    for (i = 0; i < bound1; i++) {
        for (j = 0; j < bound2; j++) {
            AssignValue(A, B[i][j], i, j);  /*������B��Ԫ�ظ�ֵ��A*/
            GetValue(&e, A, i, j);          /*������A�е�Ԫ�ظ�ֵ��e*/
            printf("A[%d][%d]=%3d\t", i, j, e); /*�������A�е�Ԫ��*/
        }

        printf("\n");
    }

    printf("��������������������Ԫ��,�����û���ַ���Ԫ��:\n");

    for (i = 0; i < bound1 * bound2; i++) { /*�������������������A�е�Ԫ��*/
        printf("��%d��Ԫ��=%3d\t", i + 1, A.base[i]);

        if ((i + 1) % bound2 == 0) {
            printf("\n");
        }
    }

    DestroyArray(&A);
}

