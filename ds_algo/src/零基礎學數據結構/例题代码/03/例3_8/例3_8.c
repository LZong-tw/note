/*����ͷ�ļ�*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/*���Ͷ���*/
typedef char DataType;
#define ListSize 10
typedef struct {    /*��̬���������Ͷ���*/
    DataType data;
    int cur;
} SListNode;
typedef struct {    /*��̬�������Ͷ���*/
    SListNode list[ListSize];
    int av;
} SLinkList;
#include "SLinkList.h"
/*��������*/
void PrintDList(SLinkList L, int n);
void main()
{
    SLinkList L;
    int i, len;
    int pos;
    char e;
    DataType a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'H'};
    DataType a1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    len = sizeof(a) / sizeof(a[0]);
    InitSList(&L);

    for (i = 1; i <= len; i++) {
        InsertSList(&L, i, a[i - 1]);
    }

    printf("��̬�����е�Ԫ��:");
    PrintDList(L, len);
    printf("����Ҫ�����Ԫ�ؼ�λ��:");
    scanf("%c", &e);
    getchar();
    scanf("%d", &pos);
    getchar();
    InsertSList(&L, pos, e);
    printf("����Ԫ�غ�̬�����е�Ԫ��:");
    PrintDList(L, len + 1);

    printf("����Ҫɾ��Ԫ�ص�λ��:");
    scanf("%d", &pos);
    getchar();
    DeleteSList(&L, pos, &e);
    printf("ɾ����Ԫ����:");
    printf("%c\n", e);
    printf("ɾ��Ԫ�غ�̬�����е�Ԫ��:");
    PrintDList(L, len);
}
void PrintDList(SLinkList L, int n)
/*���˫��ѭ�������е�ÿһ��Ԫ��*/
{
    int j, k;
    k = L.list[0].cur;

    for (j = 1; j <= n; j++) {
        printf("%4c", L.list[k].data);
        k = L.list[k].cur;
    }

    printf("\n");

}