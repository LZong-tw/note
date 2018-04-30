/*包含头文件及宏定义*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef char DataType;
#define MaxSize 100                 /*定义栈的最大容量*/
#include"LinkBiTree.h"              /*包含二叉树的二叉链表的基本操作*/
/*函数的声明*/
void PreOrderTraverse(BiTree T);    /*二叉树的先序遍历的递归函数声明*/
void InOrderTraverse(BiTree T);     /*二叉树的中序遍历的递归函数声明*/
void PostOrderTraverse(BiTree T);   /*二叉树的后序遍历的递归函数声明*/
void PreOrderTraverse2(BiTree T);   /*二叉树的先序遍历的非递归函数声明*/
void InOrderTraverse2(BiTree T);    /*二叉树的中序遍历的非递归函数声明*/
void PostOrderTraverse2(BiTree T);  /*二叉树的后序遍历的非递归函数声明*/
void CreateBitTree2(BiTree* T,
                    char str[]); /*利用括号嵌套的字符串建立二叉树的函数声明*/
int main()
{
    BiTree T, root;
    InitBitTree(&T);
    printf("根据输入二叉树的先序序列创建二叉树('#'表示结束)：\n");
    CreateBitTree(&T);
    printf("二叉树的先序序列：\n");
    printf("递归：\t");
    PreOrderTraverse(T);
    printf("\n");
    printf("非递归：");
    PreOrderTraverse2(T);
    printf("\n");
    printf("二叉树的中序序列：\n");
    printf("递归：\t");
    InOrderTraverse(T);
    printf("\n");
    printf("非递归：");
    InOrderTraverse2(T);
    printf("\n");
    printf("二叉树的后序序列：\n");
    printf("递归：\t");
    PostOrderTraverse(T);
    printf("\n");
    printf("非递归：");
    PostOrderTraverse2(T);
    printf("\n");
    printf("根据括号嵌套的字符串建立二叉树:\n");
    CreateBitTree2(&root, "(a(b(c,d),e(f(,g),h(i)))");
    printf("二叉树的先序序列：\n");
    PreOrderTraverse(root);
    printf("\n");
    printf("二叉树的中序序列：\n");
    InOrderTraverse(root);
    printf("\n");
    printf("二叉树的后序序列：\n");
    PostOrderTraverse(root);
    printf("\n");
    getch();
    DestroyBitTree(&T);
    DestroyBitTree(&root);
}

void  CreateBitTree2(BiTree* T, char str[])
/*利用括号嵌套的字符串建立二叉链表*/
{
    char ch;
    BiTree stack[MaxSize];          /*定义栈，用于存放指向二叉树中结点的指针*/
    int top = -1;                   /*初始化栈顶指针*/
    int flag, k;
    BitNode* p;
    *T = NULL, k = 0;
    ch = str[k];

    while (ch != '\0') {            /*如果字符串没有结束*/
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

            if (*T == NULL) {   /*如果是第一个结点，表示是根结点*/
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
/*先序遍历二叉树的递归实现*/
{
    if (T) {                            /*如果二叉树不为空*/
        printf("%2c", T->data);             /*访问根结点*/
        PreOrderTraverse(T->lchild);        /*先序遍历左子树*/
        PreOrderTraverse(T->rchild);        /*先序遍历右子树*/
    }
}
void InOrderTraverse(BiTree T)
/*中序遍历二叉树的递归实现*/
{
    if (T) {                            /*如果二叉树不为空*/
        InOrderTraverse(T->lchild);         /*中序遍历左子树*/
        printf("%2c", T->data);             /*访问根结点*/
        InOrderTraverse(T->rchild);         /*中序遍历右子树*/
    }
}
void PostOrderTraverse(BiTree T)
/*后序遍历二叉树的递归实现*/
{
    if (T) {                            /*如果二叉树不为空*/
        PostOrderTraverse(T->lchild);       /*后序遍历左子树*/
        PostOrderTraverse(T->rchild);       /*后序遍历右子树*/
        printf("%2c", T->data);             /*访问根结点*/
    }
}

void PreOrderTraverse2(BiTree T)
/*先序遍历二叉树的非递归实现*/
{
    BiTree stack[MaxSize];              /*定义一个栈，用于存放结点的指针*/
    int top;                            /*定义栈顶指针*/
    BitNode* p;                         /*定义一个结点的指针*/
    top = 0;                        /*初始化栈*/
    p = T;

    while (p != NULL || top > 0) {
        while (p != NULL) {             /*如果p不空，访问根结点，遍历左子树*/
            printf("%2c", p->data);         /*访问根结点*/
            stack[top++] = p;               /*将p入栈*/
            p = p->lchild;              /*遍历左子树*/
        }

        if (top > 0) {                  /*如果栈不空*/
            p = stack[--top];               /*栈顶元素出栈*/
            p = p->rchild;                  /*遍历右子树*/
        }
    }
}
void InOrderTraverse2(BiTree T)
/*中序遍历二叉树的非递归实现*/
{
    BiTree stack[MaxSize];              /*定义一个栈，用于存放结点的指针*/
    int top;                            /*定义栈顶指针*/
    BitNode* p;                         /*定义一个结点的指针*/
    top = 0;                        /*初始化栈*/
    p = T;

    while (p != NULL || top > 0) {
        while (p != NULL) {             /*如果p不空，访问根结点，遍历左子树*/
            stack[top++] = p;               /*将p入栈*/
            p = p->lchild;              /*遍历左子树*/
        }

        if (top > 0) {                  /*如果栈不空*/
            p = stack[--top];               /*栈顶元素出栈*/
            printf("%2c", p->data);         /*访问根结点*/
            p = p->rchild;                  /*遍历右子树*/
        }
    }
}

void PostOrderTraverse2(BiTree T)
/*后序遍历二叉树的非递归实现*/
{
    BiTree stack[MaxSize];              /*定义一个栈，用于存放结点的指针*/
    int top;                            /*定义栈顶指针*/
    BitNode* p, *q;                     /*定义结点的指针*/
    top = 0;                            /*初始化栈*/
    p = T, q = NULL;                    /*初始化结点的指针*/

    while (p != NULL || top > 0) {
        while (p != NULL) {                 /*如果p不空，访问根结点，遍历左子树*/
            stack[top++] = p;               /*将p入栈*/
            p = p->lchild;                  /*遍历左子树*/
        }

        if (top > 0) {                      /*如果栈不空*/
            p = stack[top - 1];                 /*取栈顶元素*/

            if (p->rchild == NULL ||
                p->rchild == q) { /*如果p没有右孩子结点，或右孩子结点已经访问过*/
                printf("%2c", p->data);         /*访问根结点*/
                q = p;
                p = NULL;
                top--;
            } else {
                p = p->rchild;
            }
        }
    }
}
