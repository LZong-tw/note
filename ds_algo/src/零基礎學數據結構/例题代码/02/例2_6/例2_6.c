#include<stdio.h>                       /*�����������*/
void main()
{
    /*ָ�����鶨��*/
    char* book[4] = {"C Programming Language", "Assembly Language", "Java Language", "Natural Language"};
    int n = 4;                      /*ָ������Ԫ�صĸ���*/
    int row;
    char* arrayPtr;
    /*��һ�ַ��������ͨ�����������*/
    printf("��һ�ַ��������ͨ��ָ�������еĸ������������:\n");

    for (row = 0; row < n; row++) {
        printf("��%d���ַ�����%s\n", row + 1, book[row]);
    }

    /*�ڶ��ַ��������ͨ��ָ�������ָ�����*/
    printf("�ڶ��ַ��������ͨ��ָ����������ָ�����:\n");

    for (arrayPtr = book[0], row = 0; row < n; arrayPtr = book[row]) {
        printf("��%d���ַ�����%s\n", row + 1, arrayPtr);
        row++;
    }
}

