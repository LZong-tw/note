#include<stdio.h>               /*���������������*/
#define N 10                    /*����Ԫ�ظ���*/
int Ascending(int a, int b);    /*�Ƿ������������*/
int Descending(int a, int b);   /*�Ƿ���н�������*/
void swap(int*, int*);          /*��������*/
void BubbleSort(int a[], int n, int (*compare)(int,
                int)); /*����ͨ������ָ����Ϊ��������*/
void Display(int a[], int n);   /*�������Ԫ��*/
void main()
{
    int a[N] = {12, 34, 21, 46, 89, 54, 26, 8, 6, 17};
    int flag;

    while (1) {
        printf("����1:��С��������.\n������2:�Ӵ�С����.\n����3:�˳�!\n");
        scanf("%d", &flag);

        switch (flag) {
        case 1:
            printf("����ǰ������Ϊ:");
            Display(a, N);
            BubbleSort(a, N, Ascending);                /*��С�������򣬽�������Ϊ��������*/
            printf("��С�������к������Ϊ:");
            Display(a, N);
            break;

        case 2:
            printf("����ǰ������Ϊ:");
            Display(a, N);
            BubbleSort(a, N, Descending);               /*�Ӵ�С���򣬽�������Ϊ��������*/
            printf("�Ӵ�С���к������Ϊ:");
            Display(a, N);
            break;

        case 3:
            return;
            break;

        default:
            printf("�������ݲ��Ϸ�������������.\n");
            break;
        }
    }

}
/*ð�����򣬽�������Ϊ�������ݣ��ж��Ǵ�С�����ǴӴ�С����*/
void BubbleSort(int a[], int n, int(*compare)(int, int))
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++)
            if ((*compare)(a[j], a[j + 1])) {
                swap(&a[j], &a[j + 1]);
            }

}
/*���������Ԫ��*/
void swap(int* a, int* b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
/*�ж��������ݴ�С�����ǰ�ߴ�����������Ҫ����*/
int Ascending(int a, int b)
{
    if (a > b) {
        return 1;
    } else {
        return 0;
    }

}
/*�ж��������ݴ�С�����ǰ�ߴ󣬽���������Ҫ����*/
int Descending(int a, int b)
{
    if (a < b) {
        return 1;
    } else {
        return 0;
    }
}
/*�������Ԫ��*/
void Display(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%4d", a[i]);
    }

    printf("\n");
}