typedef struct node {
    DataType data;
    struct node* next;
} LStackNode, *LinkStack;
void InitStack(LinkStack* top)
/*����ջ��ʼ��Ϊ�ա���̬����ͷ��㣬����ͷ����ָ������Ϊ�ա�*/
{
    if ((*top = (LinkStack)malloc(sizeof(LStackNode))) ==
        NULL) { /*Ϊͷ������һ���洢�ռ�*/
        exit(-1);
    }

    (*top)->next = NULL;            /*����ջ��ͷ���ָ������Ϊ��*/
}
int StackEmpty(LinkStack top)
/*�ж���ջ�Ƿ�Ϊ�գ�����ͨ���ж�ͷ����ָ�����Ƿ�Ϊ��*/
{
    if (top->next == NULL) {        /*�ж���ջͷ����ָ�����Ƿ�Ϊ��*/
        return 1;    /*����ջΪ��ʱ������1�����򷵻�0*/
    } else {
        return 0;
    }
}
int PushStack(LinkStack top, DataType e)
/*��ջ��������Ҫ������ĵ�һ�����ǰ����һ���½�㣬��ջ�ɹ�����1*/
{
    LStackNode*
    p;      /*����ָ���i��Ԫ�ص�ǰ�����ָ��pre��ָ��pָ�������ɵĽ��*/

    if ((p = (LStackNode*)malloc(sizeof(LStackNode))) == NULL) {
        printf("�ڴ����ʧ��!");
        exit(-1);
    }

    p->data = e;        /*ָ��pָ��ͷ���*/
    p->next = top->next;
    top->next = p;
    return 1;
}
int PopStack(LinkStack top, DataType* e)
/*ɾ���������еĵ�i��λ�õĽ�㡣ɾ���ɹ�����1��ʧ�ܷ���0*/
{
    LStackNode* p;
    p = top->next;

    if (!p) {                       /*�ж���ջ�Ƿ�Ϊ��*/
        printf("ջ�ѿ�");
        return 0;
    }

    top->next = p->next;            /*��ջ�����������Ͽ�������ջ*/
    *e = p->data;               /*����ջԪ�ظ�ֵ��e*/
    free(p);                        /*�ͷ�pָ��Ľ��*/
    return 1;
}
int StackLength(LinkStack top)
{
    LStackNode* p;
    int count = 0;
    p = top;

    while (p->next != NULL) {
        p = p->next;
        count++;
    }

    return count;
}
void DestroyStack(LinkStack top)
{
    LStackNode* p, *q;
    p = top;

    while (!p) {
        q = p;
        p = p->next;
        free(q);
    }
}
int GetTop(LinkStack top, DataType* e)
{
    LStackNode* p;
    p = top->next;

    if (!p) {                       /*�ж���ջ�Ƿ�Ϊ��*/
        printf("ջ�ѿ�");
        return 0;
    }

    *e = p->data;               /*����ջԪ�ظ�ֵ��e*/
    return 1;
}