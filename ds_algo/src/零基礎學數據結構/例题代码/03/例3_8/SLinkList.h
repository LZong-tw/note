void InitSList(SLinkList* L)
/*��̬�����ʼ����*/
{
    int i;

    for (i = 0; i < ListSize; i++) {
        (*L).list[i].cur = i + 1;
    }

    (*L).list[ListSize - 1].cur = 0;
    (*L).av = 1;
}
int AssignNode(SLinkList L)
/*�ӱ���������ȡ��һ�����ռ䣬�����Ҫ���������е�Ԫ��*/
{
    int i;
    i = L.av;
    L.av = L.list[i].cur;
    return i;
}
void FreeNode(SLinkList L, int pos)
/*ʹ���н���Ϊ���������еĽ��*/
{
    L.list[pos].cur = L.av;
    L.av = pos;
}
void InsertSList(SLinkList* L, int i, DataType e)
/*�������*/
{
    int j, k, x;
    k = (*L).av;
    (*L).av = (*L).list[k].cur;
    (*L).list[k].data = e;
    j = (*L).list[0].cur;

    for (x = 1; x < i - 1; x++) {
        j = (*L).list[j].cur;
    }

    (*L).list[k].cur = (*L).list[j].cur;
    (*L).list[j].cur = k;
}
void DeleteSList(SLinkList* L, int i, DataType* e)
/*ɾ������*/
{
    int j, k, x;
    j = (*L).list[0].cur;

    for (x = 1; x < i - 1; x++) {
        j = (*L).list[j].cur;
    }

    k = (*L).list[j].cur;
    (*L).list[j].cur = (*L).list[k].cur;
    (*L).list[k].cur = (*L).av;
    *e = (*L).list[k].data;
    (*L).av = k;
}
