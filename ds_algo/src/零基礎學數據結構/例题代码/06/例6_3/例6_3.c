/*����ͷ�ļ��������Ļ�������ʵ���ļ�*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkString.h"
void StrPrint(LinkString S);
void main()
{
    int i, j;
    int flag;
    LinkString S1, S2, S3, Sub;
    char* str1 = "Welcome to";
    char* str2 = " Data Structure";
    char* str3 = "Computer Architecture";
    printf("���ĳ�ʼ���͸�ֵ����:\n");
    InitString(&S1);                    /*��S1��S2��S3�ĳ�ʼ��*/
    InitString(&S2);
    InitString(&S3);
    InitString(&Sub);
    StrAssign(&S1, str1);               /*��S1��S2��S3�ĸ�ֵ����*/
    StrAssign(&S2, str2);
    StrAssign(&S3, str3);
    printf("��S1��ֵ��:");
    StrPrint(S1);
    printf("��S2��ֵ��:");
    StrPrint(S2);
    printf("��S3��ֵ��:");
    StrPrint(S3);
    printf("����S2�����ڴ�S1��ĩβ:\n");
    StrConcat(&S1, S2);                 /*����S2�����ڴ�S1��ĩβ*/
    printf("S1��:");
    StrPrint(S1);
    printf("����S1�ĵ�12��λ�ú��14���ַ�ɾ��:\n");
    StrDelete(&S1, 12, 14);             /*����S1�еĵ�12��λ�ú��14���ַ�ɾ��*/
    printf("S1��:");
    StrPrint(S1);
    printf("����S2���뵽��S1�еĵ�12���ַ���:\n");
    StrInsert(&S1, 12, S3);             /*����S3���뵽��S1�ĵ�12���ַ���*/
    printf("S1��:");
    StrPrint(S1);
    printf("����S1�еĵ�12���ַ����8���ַ�ȡ������ֵ����Sub:\n");
    SubString(&Sub, S1, 12,
              8);         /*����S1�еĵ�12��λ�ú��8���ַ�ȡ����ֵ��Sub*/
    printf("Sub��:");
    StrPrint(Sub);
}

void StrPrint(LinkString S)
/*���������*/
{
    int i = 0, j;
    Chunk* h;
    h = S.head;                     /*hָ���һ�����*/

    while (i < S.length) {
        for (j = 0; j < ChunkSize; j++) /*������е�ÿһ���ַ�*/
            if (*(h->ch + j) != stuff) {
                printf("%c", *(h->ch + j));
                i++;
            }

        h = h->next;            /*hָ����һ�����*/
    }

    printf("\n");
}
