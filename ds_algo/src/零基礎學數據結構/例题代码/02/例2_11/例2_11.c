#include <stdio.h>      /*���������������*/
int Max(int x, int y);  /*�����������Ľϴ��ߵĺ�������*/
void main()
{
    int a, b, s;
    scanf("%d,%d", &a, &b);
    s = Max(a, b);      /*�������������еĽϴ��ߵĺ���*/
    printf("��������%d��%d�Ľϴ���Ϊ:%d\n", a, b, s);
}
int Max(int x, int y)
/*�����������ϴ��ߵ�ʵ�ֺ����������ϴ��ֵ����*/
{
    int z;

    if (x > y) {
        z = x;
    } else {
        z = y;
    }

    return z;
}
