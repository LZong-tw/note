#include<stdio.h>           /*�����������*/
void main()
{
    int a = 10, b = 20;
    int* aPtr, *bPtr;               /*ָ���������*/
    aPtr = &a;              /*ָ�����ָ�����q*/
    bPtr = &b;
    /*��ӡ����q�ĵ�ַ��qPtr������*/
    printf("q�ĵ�ַ�ǣ�%p\nqPtr�е������ǣ�%p\n", &q, qPtr);
    /*��ӡq��ֵ��qPtrָ�����������*/
    printf("q��ֵ�ǣ�%d\n*qPtr��ֵ�ǣ�%d\n", q, *qPtr);
    /*�����'&'��'*'�ǻ����*/
    printf("&*qPtr=%p,*&qPtr=%p\n�����&*qPtr=*&qPtr\n", &*qPtr, *& qPtr);
}

