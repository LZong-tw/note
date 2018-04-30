/*����ͷ�ļ����궨��*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef char DataType;
#define MaxSize 100                 /*����ջ���������*/
#include"LinkBiTree.h"              /*�����������Ķ�������Ļ�������*/
/*����������*/
void CreateBitTree2(BiTree* T,
                    char str[]); /*��������Ƕ�׵��ַ��������������ĺ�������*/
void LevelPrint(BiTree T);
void TreePrint(BiTree T, int nLayer);
int LeafCount(BiTree T);
int NotLeafCount(BiTree T);
int BitTreeDepth(BiTree T);
void main()
{
    BiTree T, root;
    int num, depth;
    printf("��������Ƕ��(a(b(c,d),e(f(,g),h(i)))����������:\n");
    CreateBitTree2(&root, "(a(b(c,d),e(f(,g),h(i)))");
    num = LeafCount(root);
    printf("Ҷ�ӽ�����=%2d\n", num);
    num = NotLeafCount(root);
    printf("��Ҷ�ӽ�����=%2d\n", num);
    depth = BitTreeDepth(root);
    printf("�����������=%2d\n", depth);
    printf("��������Ƕ��(A(B(D(,H(J)),E(,I(K,L))),C(F,G)))����������:\n");
    CreateBitTree2(&T, "(A(B(D(,H(J)),E(,I(K,L))),C(F,G)))");
    num = LeafCount(T);
    printf("Ҷ�ӽ�����=%2d\n", num);
    num = NotLeafCount(T);
    printf("��Ҷ�ӽ�����=%2d\n", num);
    depth = BitTreeDepth(T);
    printf("�����������=%2d\n", depth);
    DestroyBitTree(&T);
    DestroyBitTree(&root);
}

void LevelPrint(BiTree T)
/*����δ�ӡ�������еĽ��*/
{
    BiTree queue[MaxSize];                      /*����һ�����У����ڴ�Ž���ָ��*/
    BitNode* p;
    int front, rear;                            /*������еĶ�ͷָ��Ͷ�βָ��*/
    front = rear = -1;                          /*���г�ʼ��Ϊ��*/
    rear++;                                     /*��βָ���1*/
    queue[rear] = T;                            /*�������ָ�����*/

    while (front != rear) {                     /*������в�Ϊ��*/
        front = (front + 1) % MaxSize;
        p = queue[front];                       /*ȡ����ͷԪ��*/
        printf("%c ", p->data);                 /*��������*/

        if (p->lchild !=
            NULL) {                /*������Ӳ�Ϊ�գ������ӽ��ָ�����*/
            rear = (rear + 1) % MaxSize;
            queue[rear] = p->lchild;
        }

        if (p->rchild !=
            NULL) {                /*����Һ��Ӳ�Ϊ�գ����Һ��ӽ��ָ�����*/
            rear = (rear + 1) % MaxSize;
            queue[rear] = p->rchild;
        }
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

void  CreateBitTree2(BiTree* T, char str[])
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
int NotLeafCount(BiTree T)
/*ͳ�ƶ������з�Ҷ�ӽ����Ŀ*/
{
    if (!T) {                               /*����ǿն�����������0*/
        return 0;
    } else if (!T->lchild && !T->rchild) {  /*�����Ҷ�ӽ�㣬����0*/
        return 0;
    } else {
        return NotLeafCount(T->lchild) + NotLeafCount(T->rchild) +
               1;    /*���������ķ�Ҷ�ӽ����Ŀ���ϸ����ĸ���*/
    }
}

int BitTreeDepth(BiTree T)
/*��������������*/
{
    if (T == NULL) {
        return 0;
    }

    return
        BitTreeDepth(T->lchild) > BitTreeDepth(T->rchild) ? 1 + BitTreeDepth(
            T->lchild) : 1 + BitTreeDepth(T->rchild);
}

int Depth(BiTree T)
{
    if (T == NULL) {
        return 0;
    }

    if (T->lchild == NULL && T->rchild == NULL) {
        return 1;
    }

    return
        Depth(T->lchild) > Depth(T->rchild) ? 1 + Depth(T->lchild) : 1 + Depth(
            T->rchild);
}