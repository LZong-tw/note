void InitList(LinkList* head)
/*���������ʼ��Ϊ�ա���̬����һ��ͷ��㣬����ͷ����ָ������Ϊ�ա�*/
{
    if ((*head = (LinkList)malloc(sizeof(ListNode))) ==
        NULL) { /*Ϊͷ������һ���洢�ռ�*/
        exit(-1);
    }

    (*head)->next = NULL;           /*���������ͷ���ָ������Ϊ��*/
}
int ListEmpty(LinkList head)
/*�жϵ������Ƿ�Ϊ�գ�����ͨ���ж�ͷ����ָ�����Ƿ�Ϊ��*/
{
    if (head->next == NULL) {       /*�жϵ�����ͷ����ָ�����Ƿ�Ϊ��*/
        return 1;    /*��������Ϊ��ʱ������1�����򷵻�0*/
    } else {
        return 0;
    }
}
ListNode* Get(LinkList head, int i)
/*���ҵ������е�i����㡣���ҳɹ����ظý���ָ���ʾ�ɹ������򷵻�NULL��ʾʧ�ܡ�*/
{
    ListNode* p;
    int j;

    if (ListEmpty(head)) { /*�ڲ��ҵ�i��Ԫ��֮ǰ���ж������Ƿ�Ϊ��*/
        return NULL;
    }

    if (i < 1) {        /*�ڲ��ҵ�i��Ԫ��֮ǰ���жϸ�����Ƿ�Ϸ�*/
        return NULL;
    }

    j = 0;
    p = head;

    while (p->next != NULL && j < i) {
        p = p->next;
        j++;
    }

    if (j == i) {
        return p;    /*�ҵ���i����㣬����ָ��p*/
    } else {
        return NULL   ;    /*���û���ҵ���i��Ԫ�أ�����NULL*/
    }
}
ListNode* LocateElem(LinkList head, DataType e)
/*�������Ա���Ԫ��ֵΪe��Ԫ�أ����ҳɹ�����ӦԪ�صĽ��ָ�뷵�أ����򷵻�NULL��ʾʧ�ܡ�*/
{
    ListNode* p;
    p = head->next;     /*ָ��pָ���һ�����*/

    while (p) {
        if (p->data != e) { /*�ҵ���e��ȵ�Ԫ�أ����ظ����*/
            p = p->next;
        } else {
            break;
        }
    }

    return p;
}
int LocatePos(LinkList head, DataType e)
/*�������Ա���Ԫ��ֵΪe��Ԫ�أ����ҳɹ�����ӦԪ�ص���ŷ��أ����򷵻�0��ʾʧ�ܡ�*/
{
    ListNode* p;
    int i;

    if (ListEmpty(head)) { /*�ڲ��ҵ�i��Ԫ��֮ǰ���ж������Ƿ�Ϊ��*/
        return 0;
    }

    p = head->next;     /*ָ��pָ���һ�����*/
    i = 1;

    while (p) {
        if (p->data == e) { /*�ҵ���e��ȵ�Ԫ�أ����ظ����*/
            return i;
        } else {
            p = p->next;
            i++;
        }
    }

    if (!p) {           /*���û���ҵ���e��ȵ�Ԫ�أ�����0����ʾʧ��*/
        return 0;
    }
}

int InsertList(LinkList head, int i, DataType e)
/*�ڵ������е�i��λ�ò���һ����㣬����Ԫ��ֵΪe������ɹ�����1��ʧ�ܷ���0*/
{
    ListNode* p,
              *pre;  /*����ָ���i��Ԫ�ص�ǰ�����ָ��pre��ָ��pָ�������ɵĽ��*/
    int j;
    pre = head;         /*ָ��pָ��ͷ���*/
    j = 0;

    while (pre->next != NULL &&
           j < i - 1) { /*�ҵ���i��1����㣬����i������ǰ�����*/
        pre = pre->next;
        j++;
    }

    if (!pre) {                 /*���û�ҵ���˵������λ�ô���*/
        printf("����λ�ô�");
        return 0;
    }

    /*������һ����㣬����e��ֵ���ý���������*/
    if ((p = (ListNode*)malloc(sizeof(ListNode))) == NULL) {
        exit(-1);
    }

    p->data = e;
    /*���������*/
    p->next = pre->next;
    pre->next = p;
    return 1;
}
int DeleteList(LinkList head, int i, DataType* e)
/*ɾ���������еĵ�i��λ�õĽ�㡣ɾ���ɹ�����1��ʧ�ܷ���0*/
{
    ListNode* pre, *p;
    int j;
    pre = head;
    j = 0;

    while (pre->next != NULL && pre->next->next != NULL &&
           j < i - 1) { /*�ж��Ƿ��ҵ�ǰ�����*/
        pre = pre->next;
        j++;
    }

    if (j != i - 1) {       /*���û�ҵ�Ҫɾ���Ľ��λ�ã�˵��ɾ��λ�ô���*/
        printf("ɾ��λ�ô���");
        return 0;
    }

    /*ָ��pָ�������еĵ�i����㣬�����ý���������ֵ��ֵ��e*/
    p = pre->next;
    *e = p->data;
    /*��ǰ������ָ����ָ��Ҫɾ��������һ����㣬Ҳ���ǽ�pָ��Ľ���뵥����Ͽ�*/
    pre->next = p->next;
    free(p);                /*�ͷ�pָ��Ľ��*/
    return 1;
}
int ListLength(LinkList head)
{
    ListNode* p;
    int count = 0;
    p = head;

    while (p->next != NULL) {
        p = p->next;
        count++;
    }

    return count;
}
void DestroyList(LinkList head)
{
    ListNode* p, *q;
    p = head;

    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
}
