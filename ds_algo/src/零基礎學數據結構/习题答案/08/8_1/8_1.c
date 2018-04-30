/*����ͷ�ļ��͹�������Ļ���������ʵ���ļ�*/
#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef char AtomType;
#include"GList.h"
#include"SeqString.h"
/*��������*/
void CreateList(GList* L, SeqString S);
void DistributeString(SeqString* Str, SeqString* HeadStr);
void PrintGList(GList L);
void main()
{
    GList L;
    SeqString S;
    StrAssign(&S, "(a,(b),(a,(b,c),d))");   /*���ַ�����ֵ����S*/
    CreateList(&L, S);                      /*�ɴ����������L*/
    printf("�Թ�������ʽ���L:\n");
    PrintGList(L);                          /*���������е�Ԫ��*/
    printf("\n");
}


void PrintGList(GList L)
/*�Թ������ʽ���������ͷβ�����ʾ*/
{
    if (!L) {               /*����������ӱ�Ϊ�գ���ֱ�����һ������(�����ź�������)*/
        printf("()");
        return;
    } else if (L->tag == ATOM) { /*�����ԭ�ӣ���ֱ�����ԭ��Ԫ��*/
        printf("%c", L->atom);
        return;
    } else {                /*������ӱ������һ��������*/
        printf("(");
    }

    for (; L; L = L->ptr.tp) {
        PrintGList(L->ptr.hp);  /*�ݹ��������ӱ�*/

        if (L->ptr.tp) {        /*�����β����Ԫ�أ������һ������*/
            printf(",");
        }

    }

    printf(")");                /*����ӱ������������һ��������*/
}
void CreateList(GList* L, SeqString S)
/*����ͷβ�����������*/
{
    SeqString Sub, HeadSub, Empty;
    GList p, q;
    StrAssign(&Empty, "()");

    if (!StrCompare(S, Empty)) {        /*�������Ĵ��ǿմ��򴴽�һ���յĹ����*/
        *L = NULL;
    } else {
        if (!(*L = (GList)malloc(sizeof(GLNode)))) { /*Ϊ���������һ�����*/
            exit(-1);
        }

        if (StrLength(S) ==
            1) {                    /*�������ԭ�ӣ���ԭ�ӵ�ֵ��ֵ���������*/
            (*L)->tag = ATOM;
            (*L)->atom = S.str[0];
        } else {                                    /*������ӱ�*/
            (*L)->tag = LIST;
            p = *L;
            SubString(&Sub, S, 2, StrLength(S) - 2); /*��Sȥ�����������ţ�Ȼ��ֵ��Sub*/

            do {
                DistributeString(&Sub,
                                 &HeadSub);   /*��Sub�������ͷ�ͱ�β�ֱ�ֵ��HeadSub��Sub*/
                CreateList(&(p->ptr.hp), HeadSub);  /*�ݹ�������ɹ����*/
                q = p;

                if (!StrEmpty(
                        Sub)) {               /*�����β���գ������ɽ��p������βָ����ָ��p*/
                    if (!(p = (GLNode*)malloc(sizeof(GLNode)))) {
                        exit(-1);
                    }

                    p->tag = LIST;
                    q->ptr.tp = p;
                }
            } while (!StrEmpty(Sub));

            q->ptr.tp = NULL;
        }
    }
}
void DistributeString(SeqString* Str, SeqString* HeadStr)
/*����Str������������֣�HeadStrΪ��һ������֮ǰ���Ӵ���StrΪ���ź���Ӵ�*/
{
    int len, i, k;
    SeqString Ch, Ch1, Ch2, Ch3;
    len = StrLength(*Str);              /*lenΪStr�ĳ���*/
    StrAssign(&Ch1, ",");               /*���ַ�','��'('��')'�ֱ𸳸�Ch1,Ch2��Ch3*/
    StrAssign(&Ch2, "(");
    StrAssign(&Ch3, ")");
    SubString(&Ch, *Str, 1, 1);         /*Ch����Str�ĵ�һ���ַ�*/

    for (i = 1, k = 0; i <= len && StrCompare(Ch, Ch1) ||
         k != 0; i++) { /*����Str�����ĵ�һ������*/
        SubString(&Ch, *Str, i, 1);     /*ȡ��Str�ĵ�һ���ַ�*/

        if (!StrCompare(Ch, Ch2)) {     /*�����һ���ַ���'('������k��1*/
            k++;
        } else if (!StrCompare(Ch, Ch3)) { /*�����ǰ�ַ���')'������k��ȥ1*/
            k--;
        }
    }

    if (i <= len) {                     /*��Str�д���','�����ǵ�i-1���ַ�*/
        SubString(HeadStr, *Str, 1, i - 2); /*HeadStr���洮Str','ǰ���ַ�*/
        SubString(Str, *Str, i, len - i + 1); /*Str���洮Str','����ַ�*/
    } else {                            /*��Str�в�����','*/
        StrCopy(HeadStr, *Str);         /*����Str�����ݸ��Ƶ���HeadStr*/
        StrClear(Str);                  /*��մ�Str*/
    }
}
