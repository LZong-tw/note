#include<stdio.h>   /*�����������ͷ�ļ�*/
void f1();          /*����f1����*/
void f2();          /*����f2����*/
void f3();          /*����f3����*/
void main()
{
    void (*f[3])() = {f1, f2, f3};      /*ָ������ָ�����������*/
    int flag;
    printf("������һ��1,2,����3. ����0�˳�.\n");
    scanf("%d", &flag);

    while (flag) {
        if (flag == 1 || flag == 2 || flag == 3) {
            f[flag - 1](flag - 1);      /*ͨ������ָ����������еĺ���*/
            printf("������һ��1,2,����3.����0�˳�.\n");
            scanf("%d", &flag);
        } else {
            printf("������һ���Ϸ�����(1-3),0�˳�.\n");
            scanf("%d", &flag);
        }
    }

    printf("�����˳�.\n");
}
void f1()                       /*����f1�Ķ���*/
{
    printf("����f1�����ã�\n"); /*����f2�Ķ���*/
}
void f2()
{
    printf("����f2�����ã�\n"); /*����f3�Ķ���*/
}
void f3()
{
    printf("����f3�����ã�\n");
}