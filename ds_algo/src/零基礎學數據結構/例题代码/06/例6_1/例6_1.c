#include<stdio.h>
#include"SeqString.h"
void StrPrint(SeqString S);
void main()
{
    SeqString S1, S2, Sub;
    char ch[MaxLength];
    printf("�������һ���ַ���:\n");
    gets(ch);
    StrAssign(&S1, ch);
    printf("�����S1��");
    StrPrint(S1);
    printf("������ڶ����ַ���:\n");
    gets(ch);
    StrAssign(&S2, ch);
    printf("�����S2��");
    StrPrint(S2);
    printf("����S2���뵽S1�ĵ�13��λ��:\n");
    StrInsert(&S1, 13, S2);
    StrPrint(S1);
    printf("����S1�еĵ�22��λ�����7���ַ�ɾ��:\n");
    StrDelete(&S1, 22, 7);
    StrPrint(S1);
    printf("����S2�еĵ�6��λ�����4�ַ�ȡ������Sub��:\n");
    SubString(&Sub, S2, 6, 4);
    StrPrint(Sub);
    printf("����Sub��ֵΪAmerica:\n");
    StrAssign(&Sub, "America");
    printf("����S1�еĴ�S2��Subȡ��:\n");
    StrReplace(&S1, S2, Sub);
    StrPrint(S1);
}
void StrPrint(SeqString S)
{
    int i;

    for (i = 0; i < S.length; i++) {
        printf("%c", S.str[i]);
    }

    printf("\n");
}
