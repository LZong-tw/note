/*����ͷ�ļ����궨��*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef char DataType;
#define MaxSize 100                 /*����ջ���������*/

typedef struct Node {           /*��������洢�ṹ���Ͷ���*/
    DataType data;              /*������*/
    struct Node* lchild;            /*ָ�����ӽ��*/
    struct Node* rchild;            /*ָ���Һ��ӽ��*/
}* BiTree, BitNode;

/*����������*/
void CreateBitTree(BiTree* T, char str[]);
void DestroyBitTree(BiTree* T);
void TreePrint(BiTree T, int nLayer);
void TreePrint(BiTree T, int level);
void main()
{
    BiTree T;
    int num, level;
    printf("��������Ƕ��(a(b(c,d),e(f(,g)))����������:\n");
    CreateBitTree(&T, "(a(b(c,d),e(f(,g)))");
    level = TreeDepth(T);
    printf("����״��ӡ��������\n");
    TreePrint(T, level);
    num = LeafCount(T);
    printf("Ҷ�ӽ�����=%2d\n", num);
    num = TreeCount(T);
    printf("�������=%2d\n", num);
    DestroyBitTree(&T);
}
int TreeCount(BiTree T)
/*ͳ�ƽ��ĸ���*/
{
    if (T == NULL) {
        return 0;
    }

    return 1 + TreeCount(T->lchild) + TreeCount(T->rchild);
}

void TreePrint(BiTree T, int level)
/*����״��ӡ�Ķ�����*/
{
    int i;

    if (T == NULL) {                            /*���ָ��Ϊ�գ�������һ��*/
        return;
    }

    TreePrint(T->rchild, level + 1);            /*��ӡ��������������μ�1*/

    for (i = 0; i < level; i++) {               /*���յݹ�Ĳ�δ�ӡ�ո�*/
        printf("   ");
    }

    printf("%c\n", T->data);                    /*��������*/
    TreePrint(T->lchild, level + 1);            /*��ӡ��������������μ�1*/
}
int LeafCount(BiTree T)
/*ͳ�ƶ�������Ҷ�ӽ����Ŀ*/
{
    if (!T) {                               /*����ǿն�����������0*/
        return 0;
    } else if (!T->lchild && !T->rchild) {    /*�������������������Ϊ�գ�����1*/
        return 1;
    } else {
        return LeafCount(T->lchild) + LeafCount(
                   T->rchild);    /*��������Ҷ�ӽ�������������Ҷ�ӽ��������*/
    }
}
int TreeDepth(BiTree T)
/*��������������*/
{
    if (T == NULL) {
        return 0;
    }

    return
        TreeDepth(T->lchild) > TreeDepth(T->rchild) ? 1 + TreeDepth(
            T->lchild) : 1 + TreeDepth(T->rchild);
}
void  CreateBitTree(BiTree* T, char str[])
/*��������Ƕ�׵��ַ���������������*/
{
    char ch;
    BiTree stack[MaxSize];          /*����ջ�����ڴ��ָ��������н���ָ��*/
    int top = -1;                   /*��ʼ��ջ��ָ��*/
    int flag, k;
    BitNode* p;
    *T = NULL, k = 0;
    ch = str[k];

    while (ch != '\0') {            /*����ַ���û�н���*/
        switch (ch) {
        case '(':
            stack[++top] = p;
            flag = 1;
            break;

        case ')':
            top--;
            break;

        case ',':
            flag = 2;
            break;

        default:
            p = (BiTree)malloc(sizeof(BitNode));
            p->data = ch;
            p->lchild = NULL;
            p->rchild = NULL;

            if (*T == NULL) {   /*����ǵ�һ����㣬��ʾ�Ǹ����*/
                *T = p;
            } else {
                switch (flag) {
                case 1:
                    stack[top]->lchild = p;
                    break;

                case 2:
                    stack[top]->rchild = p;
                    break;
                }
            }
        }

        ch = str[++k];
    }
}
void DestroyBitTree(BiTree* T)
/*���ٶ���������*/
{
    if (*T) {                       /*����Ƿǿն�����*/
        if ((*T)->lchild) {
            DestroyBitTree(&((*T)->lchild));
        }

        if ((*T)->rchild) {
            DestroyBitTree(&((*T)->rchild));
        }

        free(*T);
        *T = NULL;
    }
}
