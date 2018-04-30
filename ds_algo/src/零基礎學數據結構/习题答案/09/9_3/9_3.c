/*����ͷ�ļ����궨��*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef char DataType;
#define MaxSize 100                 /*����ջ���������*/

typedef struct Node {           /*��������洢�ṹ���Ͷ���*/
    DataType data;              /*������*/
    struct Node* lchild;        /*ָ�����ӽ��*/
    struct Node* rchild;        /*ָ���Һ��ӽ��*/
}* BiTree, BitNode;
typedef struct {                /*ջ���Ͷ���*/
    BiTree p;
    int flag;
} Stack[MaxSize];
/*����������*/
void CreateBitTree(BiTree* T, char str[]);
void DestroyBitTree(BiTree* T);
void TreePrint(BiTree T, int level);
BiTree Point(BiTree T, DataType e);
void main()
{
    BiTree T, p;
    int level;
    printf("��������Ƕ��(a(b(c,d),e(f,g)))����������:\n");
    CreateBitTree(&T, "(a(b(c,d(h,i)),e(f,g)))");
    level = TreeDepth(T);
    printf("����״��ӡ��������\n");
    TreePrint(T, level);
    p = Point(T, 'h');
    Ancestor(T, p);
    DestroyBitTree(&T);
}
int Ancestor(BiTree T, BitNode* p)
/*������*p���������Ƚ��*/
{
    Stack s;
    BitNode* r = T;
    int top = 0, i;

    while (1) {
        while (r != NULL &&
               r != p) { /*������ǿն������ҵ�ǰ��㲻�ǽ��*p���򽫵�ǰ���ָ������ӽ����ջ*/
            top++;
            s[top].p = r;
            s[top].flag = 0;
            r = r->lchild;
        }

        if (r != NULL && r == p) { /*������*p���������Ƚ��*/
            printf("%c��������", p->data);

            for (i = 1; i < top; i++) {
                printf("%2c,", s[i].p->data);
            }

            printf("%2c\n", s[i].p->data);
            break;
        } else { /*�����ǰ��㲻��*p����������ջ��������ǰ���ʽ������Ѿ����ʣ��������Һ��ӽ����Ϊ��ǰ���*/
            while (top > 0 && s[top].flag == 1) {
                top--;
            }

            if (top > 0) {
                s[top].flag = 1;
            }

            r = s[top].p->rchild;
        }
    }
}
BiTree Point(BiTree T, DataType e)
/*����Ԫ��ֵΪe�Ľ���ָ��*/
{
    BiTree Q[MaxSize];          /*����һ�����У����ڴ�Ŷ������н���ָ��*/
    int front = 0, rear = 0;        /*��ʼ������*/
    BitNode* p;

    if (T) {                    /*����������ǿ�*/
        Q[rear] = T;
        rear++;

        while (front != rear) { /*������зǿ�*/
            p = Q[front];           /*ȡ����ͷָ��*/
            front++;            /*����ͷָ�����*/

            if (p->data == e) {
                return p;
            }

            if (p->lchild) {        /*������ӽ����ڣ�������ָ�����*/
                Q[rear] = p->lchild; /*���ӽ���ָ�����*/
                rear++;
            }

            if (p->rchild) {        /*����Һ��ӽ����ڣ����Һ���ָ�����*/
                Q[rear] = p->rchild; /*�Һ��ӽ���ָ�����*/
                rear++;
            }
        }
    }

    return NULL;
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