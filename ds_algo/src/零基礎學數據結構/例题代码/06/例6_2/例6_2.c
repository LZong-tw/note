/*����ͷ�ļ��ʹ���ʵ���ļ�*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"HeapString.h"
void StrPrint(HeapString S);    /*���������������*/
void main()
{
    HeapString S1, S2, Sub;
    char* p;
    char ch[50];
    /*��ʼ����S1��S2��Sub*/
    InitString(&S1);
    InitString(&S2);
    InitString(&Sub);
    printf("�������һ���ַ�����");
    gets(ch);
    StrAssign(&S1, ch);             /*ͨ�����뽫��S1��ֵ*/
    printf("������ֵ������Ĵ�S1��\n");
    StrPrint(S1);
    printf("������ڶ����ַ�����");
    gets(ch);
    StrAssign(&S2, ch);             /*ͨ�����뽫��S2��ֵ*/
    printf("������ֵ������Ĵ�S2��\n");
    StrPrint(S2);
    printf("�Ѵ�S2�����ڴ�S1��ĩβ��S1��Ϊ��\n");
    StrCat(&S1, S2);                /*����S2�����ڴ�S1��ĩβ*/
    StrPrint(S1);
    printf("������ֵ������Ĵ�Sub��\n");
    StrAssign(&Sub, "Everyone");    /*����Sub��ֵ*/
    StrPrint(Sub);
    printf("����S2���뵽��S1�ĵ�һλ�ã�\n");
    StrInsert(&S1, 1, Sub);         /*����Sub���뵽��S1�ĵ�һλ��*/
    StrPrint(S1);
    printf("�Ѵ�S1�ĵ�1��λ��֮���8���ַ�ɾ����\n");
    StrDelete(&S1, 1, 8);           /*����S1�ĵ�һλ�ú��8���ַ�ɾ��*/
    StrPrint(S1);
    printf("����S1�е�S2�û�ΪSub��\n");
    StrAssign(&Sub, "Xi'an");       /*����Sub���¸�ֵ*/
    StrReplace(&S1, S2, Sub);       /*�ô�Subȡ����S1�е�S2*/
    StrPrint(S1);
    /*����S1��S2��Sub���ڴ浥Ԫ�ͷ�*/
    StrDestroy(&S1);
    StrDestroy(&S2);
    StrDestroy(&Sub);
}
void StrPrint(HeapString S)
{
    int i;

    for (i = 0; i < S.length; i++) {
        printf("%c", S.str[i]);
    }

    printf("\n");
}
