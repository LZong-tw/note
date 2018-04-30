

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
void LevelPrint(BiTree T);                  /*���������������Ľ��*/
void TreePrint(BiTree T, int nLayer);       /*����״��ӡ������*/
void main()
{
    BiTree T, root;
    printf("��������Ƕ��(a(b(c,d),e(f(,g),h(i)))����������:\n");
    CreateBitTree2(&T, "(a(b(c,d),e(f(,g),h(i)))");
    printf("�������������������У�\n");
    LevelPrint(T);
    printf("\n");
    printf("����״��ӡ��������\n");
    TreePrint(T, 1);
    printf("��������Ƕ��(A(B(D(,H),E(,I)),C(F,G)))����������:\n");
    CreateBitTree2(&root, "(A(B(D(,H),E(,I)),C(F,G)))");
    printf("�������������������У�\n");
    LevelPrint(root);
    printf("\n");
    printf("����״��ӡ��������\n");
    TreePrint(root, 1);
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


void PreOrderTraverse(BiTree T)
/*��������������ĵݹ�ʵ��*/
{
    if (T) {                            /*�����������Ϊ��*/
        printf("%2c", T->data);             /*���ʸ����*/
        PreOrderTraverse(T->lchild);        /*�������������*/
        PreOrderTraverse(T->rchild);        /*�������������*/
    }
}
void InOrderTraverse(BiTree T)
/*��������������ĵݹ�ʵ��*/
{
    if (T) {                            /*�����������Ϊ��*/
        InOrderTraverse(T->lchild);         /*�������������*/
        printf("%2c", T->data);             /*���ʸ����*/
        InOrderTraverse(T->rchild);         /*�������������*/
    }
}
void PostOrderTraverse(BiTree T)
/*��������������ĵݹ�ʵ��*/
{
    if (T) {                            /*�����������Ϊ��*/
        PostOrderTraverse(T->lchild);       /*�������������*/
        PostOrderTraverse(T->rchild);       /*�������������*/
        printf("%2c", T->data);             /*���ʸ����*/
    }
}


