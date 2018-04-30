#include<stdio.h>
#define MaxLength 60
typedef struct { /*���Ķ���*/
    char str[MaxLength];
    int length;
} SeqString;


void StrAssign(SeqString* S, char* cstr)
/*���ĸ�ֵ����*/
{
    int i = 0;

    for (i = 0; cstr[i] != '\0'; i++) { /*������cstr�е��ַ���ֵ����S*/
        S->str[i] = cstr[i];
    }

    S->length = i;
}
int StrEmpty(SeqString S)
/*�жϴ��Ƿ�Ϊ�գ���Ϊ�շ���1�����򷵻�0*/
{
    if (S.length == 0) {    /*�жϴ��ĳ����Ƿ����0*/
        return 1;    /*����Ϊ��ʱ������1�����򷵻�0*/
    } else {
        return 0;
    }
}

int StrIndex(SeqString S, int pos, SeqString T)
/*������S�еĵ�pos��λ�ÿ�ʼ�����Ӵ�T������ҵ������Ӵ���������λ�ã����򣬷���-1*/
{
    int i, j;

    if (StrEmpty(T)) {              /*�����TΪ�գ��򷵻�0*/
        return 0;
    }

    i = pos;
    j = 0;

    while (i < S.length && j < T.length) {
        if (S.str[i] ==
            T.str[j]) { /*�����S�ʹ�T�ж�Ӧλ���ַ���ȣ�������Ƚ���һ���ַ�*/
            i++;
            j++;
        } else {                /*�����ǰ��Ӧλ�õ��ַ�����ȣ���Ӵ�S����һ���ַ���ʼ��T�ĵ�0���ַ���ʼ�Ƚ�*/
            i = i - j + 1;
            j = 0;
        }
    }

    if (j >= T.length) {            /*�����S���ҵ���T���򷵻��Ӵ�T������S��λ��*/
        return i - j + 1;
    } else {
        return -1;
    }
}

int DelString(SeqString* S, int pos, int len)
/*�ڴ�S��ɾ��pos��ʼ��len���ַ�*/
{
    int i;

    if (pos < 0 || len < 0 ||
        pos + len - 1 > S->length) { /*����������Ϸ����򷵻�0*/
        printf("ɾ��λ�ò���ȷ������len���Ϸ�");
        return 0;
    } else {
        for (i = pos + len; i <= S->length - 1;
             i++) { /*����S�ĵ�pos��λ���Ժ��len���ַ����ǵ�*/
            S->str[i - len] = S->str[i];
        }

        S->length = S->length - len;            /*�޸Ĵ�S�ĳ���*/
        return 1;
    }
}
void StrPrint(SeqString S)
/*��S�����*/
{
    int i;

    for (i = 0; i < S.length; i++) {
        printf("%c", S.str[i]);
    }

    printf("\n");
}
int Count(SeqString S1, SeqString S2)
/*ͳ�ƴ�S2�ڴ�S1�г��ֵĴ���*/
{
    int n = 1, f = 1, count = 0;

    while (f != -1) {
        f = StrIndex(S1, n, S2);    /*�ڴ�S1�в��Ҵ�S2��λ��*/
        n = f;
        n++;

        if (f != -1) {              /*���S2��S1�г���һ�Σ���count��1*/
            count++;
        }
    }

    return count;
}
void main()
{
    SeqString S1, S2, Sub;
    char ch1[] = "abcaabcbcacaabccaabcca";
    char ch2[] = "caabc";
    int n;
    StrAssign(&S1, ch1);            /*���ַ�����ֵ��S1*/
    printf("��һ����s1:");
    StrPrint(S1);
    StrAssign(&S2, ch2);            /*���ַ�����ֵ��S2*/
    printf("�ڶ�����s2:");
    StrPrint(S2);
    n = Count(S1, S2);      /*ͳ�ƴ�S2�ڴ�S1�г��ֵĴ���*/
    printf("��S2�ڴ�S1���ֵĴ�����:%2d\n", n);
    StrPrint(S1);
}

