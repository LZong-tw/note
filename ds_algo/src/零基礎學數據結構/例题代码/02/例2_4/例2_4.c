#include<stdio.h>                       /*�����������*/
void main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int* aPtr, i;                       /*ָ���������*/
    aPtr = &a[0];                       /*ָ�����ָ�����q*/

    for (i = 0; i < 5; i++) {                   /*ͨ�������±�����Ԫ��*/
        printf("a[%d]=%d\n", i, a[i]);
    }

    for (i = 0; i < 5; i++) {                   /*ͨ������������Ԫ��*/
        printf("*(a+%d)=%d\n", i, *(a + i));
    }

    for (i = 0; i < 5; i++) {                   /*ͨ��ָ������±�����Ԫ��*/
        printf("aPtr[%d]=%d\n", i, aPtr[i]);
    }

    for (aPtr = a, i = 0; aPtr < a + 5; aPtr++, i++) { /*ͨ��ָ�����ƫ������Ԫ��*/
        printf("*(aPtr+%d)=%d\n", i, *aPtr);
    }
}

