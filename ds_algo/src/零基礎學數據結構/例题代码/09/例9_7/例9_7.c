/*����ͷ�ļ�*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
/*���ĺ����ֵ�������*/
typedef int DataType;
typedef struct CSNode {
    struct CSNode* firstchild, *nextsibling;
    DataType data;
} CSNode, *CSTree;
void InitCSTree(CSTree* T);
void DestroyCSTree(CSTree* T);
void CreateCSTree(CSTree* T, DataType* e, int* index);
int DepCSTree(CSTree T);
int PreTraverseCSTree(CSTree T, void(*visit)(DataType* e));
int PostTraverseCSTree(CSTree T, void(*visit)(DataType* e));
void DisplayCSTree(DataType* e);
void InitCSTree(CSTree* T)
/*���ĳ�ʼ��*/
{
    *T = 0;
}
void DestroyCSTree(CSTree* T)
/*�������ٲ���*/
{
    CSTree p = *T;

    if (p) {
        DestroyCSTree(&(p->firstchild));/*���ٵ�һ�����ӽ��*/
        DestroyCSTree(&(p->nextsibling));/*�����ֵܽ��*/
        free(p);
        *T = 0;
    }
}
void CreateCSTree(CSTree* T, DataType* e, int* index)
/*����������*/
{
    if (e[*index] == 0) {
        *T = 0;
        (*index)++;
    } else {
        *T = (CSTree)malloc(sizeof(CSNode)); /*���ɽ��*/
        (*T)->data = e[*index];
        (*index)++;
        CreateCSTree(&((*T)->firstchild), e, index); /*������һ�����ӽ��*/
        CreateCSTree(&((*T)->nextsibling), e, index); /*�����ֵܽ��*/
        return;
    }
}

int DepCSTree(CSTree T)
/*���������*/
{
    CSNode* p;
    int k, d = 0;

    if (T == NULL) {        /*����ǿ���������0*/
        return 0;
    }

    p = T->firstchild;      /*pָ�����ĵ�һ���ӽ��*/

    while (p != NULL) {
        k = DepCSTree(p);   /*����p�������*/

        if (d < k) {
            d = k;    /*d��������������*/
        }

        p = p->nextsibling; /*����p����һ�����*/
    }

    return d + 1;

}

int PreTraverseCSTree(CSTree T, void(*visit)(DataType* e))
/*�����ȸ�����*/
{
    if (T) {
        (*visit)(&T->data);
        PreTraverseCSTree(T->firstchild, visit);
        PreTraverseCSTree(T->nextsibling, visit);
    }
}
int PostTraverseCSTree(CSTree T, void(*visit)(DataType* e))
/*���ĺ������*/
{
    if (T) {
        PostTraverseCSTree(T->firstchild, visit);
        (*visit)(&T->data);
        PostTraverseCSTree(T->nextsibling, visit);
    }
}

void DisplayCSTree(DataType* e)
/*������Ľ��*/
{
    printf("%2c", *e);
}


main()
{
    int test[] = {'A', 'B', 'E', 0, 'F', 'H', 0, 'I', 0, 'J', 0, 0, 0, 'C', 0, 'D', 'G', 0, 0, 0, 0};
    int h = 0;
    CSTree T;
    InitCSTree(&T);
    CreateCSTree(&T, test, &h);
    printf("�����ȸ����������:\n");
    PreTraverseCSTree(T, DisplayCSTree);
    printf("\n");
    printf("���ĺ�����������:\n");
    PostTraverseCSTree(T, DisplayCSTree);
    printf("\n");
    printf("���������:%2d", DepCSTree(T));
    printf("\n");
    DestroyCSTree(&T);

}

