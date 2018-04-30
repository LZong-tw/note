#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct polyn {
    float coef;      /*���һԪ����ʽ��ϵ��*/
    int expn;        /*���һԪ����ʽ��ָ��*/
    struct polyn* next;
} PolyNode, *PolyNomial;

PolyNomial CreatePolyn()
/*����һԪ����ʽ*/
{

    PolyNode* p, *q, *s;
    PolyNode* head = NULL;
    int expn2;
    float coef2;
    head = (PolyNomial)malloc(sizeof(PolyNode));

    if (!head) {
        return NULL;
    }

    head->coef = 0;
    head->expn = 0;
    head->next = NULL;

    do {
        printf("����ϵ��coef");
        scanf("%f", &coef2);
        printf("����ָ��exp(����0 0 ����)");
        scanf("%d", &expn2);

        if ((long)coef2 == 0 && expn2 == 0) {
            break;
        }

        s = (PolyNode*)malloc(sizeof(PolyNode));

        if (!s) {
            return NULL;
        }

        s->expn = expn2;
        s->coef = coef2;
        q = head->next;
        p = head;

        /*����һ������ʽ��ʹ����ʽ����ϵ���ݼ�����*/
        while (q && expn2 < q->expn) {
            p = q;
            q = q->next;
        }

        if (q == NULL || expn2 > q->expn) {
            p->next = s;
            s->next = q;
        } else {            /*���ָ����ͬ���ϲ�ͬ����*/
            q->coef += coef2;
        }
    } while (1);

    return head;
}
PolyNode* Reverse(PolyNomial head)
/*��������*/
{
    PolyNode* q, *r, *p = NULL;
    q = head->next;

    while (q) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }

    head->next = p;
    return head;
}

PolyNode* MultiplyPolyn(PolyNomial A, PolyNomial B)
/*һԪ����ʽ�����*/
{
    PolyNode* pa, *Pb, *Pc, *u, *head;
    int k, maxExp;
    float coef;
    head = (PolyNomial)malloc(sizeof(PolyNode));

    if (!head) {
        return NULL;
    }

    head->coef = 0.0;
    head->expn = 0;
    head->next = NULL;

    if (A->next != NULL && B->next != NULL) { /*�����������ʽ�˻�����ָ����*/
        maxExp = A->next->expn + B->next->expn;
    } else {
        return head;
    }

    Pc = head;
    B = Reverse(B);                     /*������ʽB����*/

    for (k = maxExp; k >= 0; k--) {
        pa = A->next;

        while (pa != NULL && pa->expn > k) {
            pa = pa->next;
        }

        Pb = B->next;

        while (Pb != NULL && pa != NULL && pa->expn + Pb->expn < k) {
            Pb = Pb->next;
        }

        coef = 0.0;

        while (pa != NULL && Pb != NULL) {

            if (pa->expn + Pb->expn == k) {
                coef += pa->coef * Pb->coef;
                pa = pa->next;
                Pb = Pb->next;
            } else if (pa->expn + Pb->expn > k) { /*˵���˻�û�е���k��ָ����*/
                pa = pa->next;
            } else {
                Pb = Pb->next;
            }
        }

        if (coef != 0.0) {
            u = (PolyNode*)malloc(sizeof(PolyNode));
            u->coef = coef;
            u->expn = k;
            u->next = Pc->next;
            Pc->next = u;
            Pc = u;
        }
    }

    B = Reverse(B);
    return head;
}
void OutPut(PolyNomial head)
/*���һԪ����ʽ*/
{
    PolyNode* p = head->next;

    while (p) {
        printf("%1.1f", p->coef);

        if (p->expn) {
            printf("*x^%d", p->expn);
        }

        if (p->next && p->next->coef > 0) {
            printf("+");
        }

        p = p->next;
    }
}

void main()
{
    PolyNomial A, B, C;
    A = CreatePolyn();
    printf("A(x)=");
    OutPut(A);
    printf("\n");
    B = CreatePolyn();
    printf("B(x)=");
    OutPut(B);
    printf("\n");
    C = MultiplyPolyn(A, B);
    printf("C(x)=A(x)*B(x)=");
    OutPut(C);
    printf("\n");
}
