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
void TreePrint(BiTree T, int level);
void main()
{
    BiTree T;
    int level, flag;
    printf("��������Ƕ��(a(b(c,d),e(f,g)))����������:\n");
    CreateBitTree(&T, "(a(b(c,d),e(f,g)))");
    level = TreeDepth(T);
    printf("����״��ӡ��������\n");
    TreePrint(T, level);
    flag = CompleteTree(T);

    if (flag == 1) {
        printf("�ö���������ȫ������.\n");
    }

    DestroyBitTree(&T);
}
int CompleteTree(BiTree T)
/*�ж϶������Ƿ�����ȫ������*/
{
    BiTree queue[MaxSize], p;
    int front = 0, rear = 0, flag = 1, flag1 = 1;

    if (T == NULL) {            /*����ǿն�����������1*/
        return 1;
    } else {
        queue[++rear] = T;      /*����������*/

        while (front != rear) {
            p = queue[++front];

            if (p->lchild ==
                NULL) { /*���*p��������Ϊ�գ���������Ϊ�գ���˵��������ȫ������*/
                flag1 = 0;

                if (p->rchild != NULL) {
                    flag = 0;
                }
            } else {            /*���*p����������Ϊ�գ�����������ӡ�*/
                flag = flag1;
                queue[++rear] = p->lchild;

                if (p->rchild == NULL) { /*���*p��������Ϊ�գ���˵��������ȫ������*/
                    flag1 = 0;
                } else {            /*���*p����������Ϊ�գ������������*/
                    queue[++rear] = p->rchild;
                }
            }
        }

        return flag;
    }
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