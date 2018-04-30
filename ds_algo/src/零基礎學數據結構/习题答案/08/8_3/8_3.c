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
int Count(GList L);
void main()
{
    GList L;
    SeqString S;
    int c;
    StrAssign(&S, "(a,(b),(a,(b,c),d))");   /*���ַ�����ֵ����S*/
    CreateList(&L, S);                      /*�ɴ����������L*/
    printf("�����L:\n");
    PrintGList(L);                          /*���������е�Ԫ��*/
    printf("\n");
    c = Count(L);
    printf("�����L��ԭ�ӵĸ�����count=%2d\n", c);

}
int Count(GList L)
/*ͳ��ԭ�ӽ��ĸ���*/
{
    int n1, n2;

    if (L == NULL) {        /*��������Ϊ�գ��򷵻�0*/
        return 0;
    } else {
        if (L->tag == ATOM) { /*�����ԭ�ӣ�����Ҫ����ԭ���Ƿ����ֵܽ��*/
            return 1 + Count(L->tp);
        } else {            /*������ӱ�����Ҫ�����ֵܽ���������һ��ԭ�ӽ������ĺ�*/
            return Count(L->tp) + Count(L->ptr.hp);
        }
    }
}

void PrintGList(GList L)
/*�Թ�������ʽ���*/
{
    if (L->tag == LIST) {
        printf("(");            /*����ӱ���ڣ������������ */

        if (L->ptr.hp == NULL) { /*����ӱ�Ϊ�գ������' '�ַ� */
            printf(" ");
        } else {                /*�ݹ������ͷ*/
            PrintGList(L->ptr.hp);
        }

        printf(")");            /*���ӱ�������������� */
    } else {                    /*�����ԭ�ӣ����������ֵ*/
        printf("%c", L->ptr.atom);
    }

    if (L->tp != NULL) {

        printf(", ");           /*�������*/
        PrintGList(L->tp);      /*�ݹ������β*/
    }
}
void CreateList(GList* L, SeqString S)
/*������չ���������������*/
{
    SeqString Sub, HeadSub, Empty;
    GList p, q;
    StrAssign(&Empty, "()");

    if (!(*L = (GList)malloc(sizeof(GLNode)))) { /*Ϊ���������һ�����*/
        exit(-1);
    }

    if (!StrCompare(S,
                    Empty)) {                /*�������Ĵ��ǿմ��򴴽�һ���յĹ����*/
        (*L)->tag = LIST;
        (*L)->ptr.hp = (*L)->tp = NULL;
    } else {

        if (StrLength(S) ==
            1) {                    /*�������ԭ�ӣ���ԭ�ӵ�ֵ��ֵ���������*/
            (*L)->tag = ATOM;
            (*L)->ptr.atom = S.str[0];
            (*L)->tp = NULL;
        } else {                                    /*������ӱ�*/
            (*L)->tag = LIST;
            (*L)->tp = NULL;
            SubString(&Sub, S, 2, StrLength(S) - 2); /*��Sȥ�����������ţ�Ȼ��ֵ��Sub*/
            DistributeString(&Sub,
                             &HeadSub);       /*��Sub�������ͷ�ͱ�β�ֱ�ֵ��HeadSub��Sub*/
            CreateList(&((*L)->ptr.hp), HeadSub);   /*�ݹ�������ɹ����*/
            p = (*L)->ptr.hp;

            while (!StrEmpty(
                       Sub)) {                /*�����β���գ������ɽ��p������βָ����ָ��p*/
                DistributeString(&Sub, &HeadSub);
                CreateList(&(p->tp), HeadSub);
                p = p->tp;
            }

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
