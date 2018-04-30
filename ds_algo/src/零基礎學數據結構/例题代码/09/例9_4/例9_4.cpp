#include <iostream>
using namespace std;
typedef char type;

//��־���ֵ,link��ʾָ�룬thread��ʾ����
typedef enum {link, thread} tag;

//�������Ķ��������洢��ʾ

typedef struct bin {
    type data;
    struct bin* lchild;  //����ָ��
    struct bin* rchild; //�Һ���ָ��
    tag ltag;              //���־λ
    tag rtag;             //�ұ�־λ
} bin_thr_node, *bin_thr_tree;

//����ȫ�ֱ���pre����¼�ոշ��ʹ��Ľڵ�
bin_thr_tree pre;

//�ݹ�������������

void in_threading(bin_thr_tree tree)
{
    if (tree) {
        in_threading(tree->lchild);    //������������

        if (!tree->lchild) { //����������Ϊ�գ���ָ��ǰ��
            tree->ltag = thread;
            tree->lchild = pre;
        }

        if (!pre->rchild) { //ǰ����������Ϊ�գ�����������ָ��ǰ���
            pre->rtag = thread;
            pre->rchild = tree;
        }

        pre = tree;                            //����preָ��tree��ǰ��
        in_threading(tree->rchild);   //������������
    }
}

//������������
int inorder_thr(bin_thr_tree& thr, bin_thr_tree t)
{
    thr = new bin_thr_node;
    thr->data = 0;
    thr->ltag = link;
    thr->rtag = thread;
    thr->rchild = thr;  //�Һ��ӻ�ָ

    if (!t) {           //����tΪ�գ���thr�����ӻ�ָ
        thr->lchild = thr;
    } else {
        thr->lchild = t;
        pre = thr;
        in_threading(t);
        pre->rchild = thr;
        pre->rtag = thread;
        thr->rchild = pre;
    }

    return 1;
}

//���򴴽�������.

//�������������������н���ֵ(һ���ַ�)�� �ַ�'#'��ʾ������

void pre_create_tree(bin_thr_tree& t)
{
    char ch;
    scanf("%c", &ch);

    if ('#' == ch) {
        t = NULL;
    } else {
        t = new bin_thr_node;
        t->data = ch;
        t->ltag = link;
        t->rtag = link;
        pre_create_tree(t->lchild);
        pre_create_tree(t->rchild);
    }
}

//  ���������߹�������

void in_order_traverse(bin_thr_tree t)
{
    bin_thr_tree point;
    point = t->lchild;

    while (point != t) {
        while (link == point->ltag) {
            point = point->lchild;
        }

        //��������˵ĺ���
        printf("%c", point->data);

        //���ʺ�̽��
        while (thread == point->rtag &&
               point->rchild != t) { //��ס��point->rchild != t;
            point = point->rchild;
            printf("%c", point->data);
        }

        //�������̽����Һ���(���̵Ľ������ӱ�Ϊ��ǰ�����ʱط��ʹ��������ٷ���)
        point = point->rchild;
    }
}



int main()
{
    bin_thr_tree t, thr;

    //���򴴽�������
    pre_create_tree(t);

    //������������
    inorder_thr(thr, t);

    //��������������
    in_order_traverse(thr);
    printf("\n");
    return 0;
}

