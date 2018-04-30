
typedef enum {ATOM, LIST} ElemTag; /*ATOM=0����ʾԭ�ӣ�LIST=1����ʾ�ӱ�*/
typedef struct {
    ElemTag tag;                    /*��־λtag��������Ԫ����ԭ�ӻ����ӱ�*/
    union {
        AtomType atom;              /*AtomType��ԭ�ӽ���ֵ���û��Լ���������*/
        struct GLNode* hp;      /*hpָ���ͷ��tpָ���β*/
    } ptr;
    struct GLNode* tp;
}* GList, GLNode;


GLNode* GetHead(GList L)
/*������ı�ͷ������*/
{
    GLNode* p;
    p = L->ptr.hp;                  /*�������ı�ͷָ�븳ֵ��p*/

    if (!p) {                       /*��������Ϊ�ձ��򷵻�1*/
        printf("�ù�����ǿձ�");
        return NULL;
    } else if (p->tag == LIST) {
        printf("�ù����ı�ͷ�Ƿǿյ��ӱ�");
    } else {
        printf("�ù����ı�ͷ��ԭ�ӡ�");
    }

    return p;
}

GLNode* GeTail(GList L)
/*������ı�β����*/
{
    GLNode* p, *tail;
    p = L->ptr.hp;

    if (!p) {                       /*��������Ϊ�ձ��򷵻�1*/
        printf("�ù�����ǿձ�");
        return NULL;
    }

    tail = (GLNode*)malloc(sizeof(GLNode)); /*����tail���*/
    tail->tag = LIST;                       /*����־����ΪLIST*/
    tail->ptr.hp = p->tp;                   /*��tail�ı�ͷָ����ָ������ı�β*/
    tail->tp = NULL;                    /*��tail�ı�βָ������Ϊ��*/
    return tail;                            /*����ָ�������β����ָ��*/
}

int GListLength(GList L)
/*������ĳ��Ȳ���*/
{
    int length = 0;                     /*��ʼ���������ĳ���*/
    GLNode* p = L->ptr.hp;

    while (p) {                         /*��������ǿգ���pָ���βָ�룬ͳ�Ʊ�ĳ���*/
        length++;
        p = p->tp;
    }

    return length;
}

int GListDepth(GList L)
/*���������Ȳ���*/
{
    int max, depth;
    GLNode* p;

    if (L->tag == LIST && L->ptr.hp == NULL) { /*��������ǿգ��򷵻�1*/
        return 1;
    }

    if (L->tag == ATOM) {               /*����������ԭ�ӣ��򷵻�0*/
        return 0;
    }

    p = L->ptr.hp;

    for (max = 0; p; p = p->tp) {       /*��㴦������*/
        depth = GListDepth(p);

        if (max < depth) {
            max = depth;
        }
    }

    return max + 1;
}

void CopyList(GList* T, GList L)
/*�����ĸ��Ʋ������ɹ����L���Ƶõ������T*/
{
    if (!L) {                       /*��������Ϊ�գ���TΪ�ձ�*/
        *T = NULL;
    } else {
        *T = (GList)malloc(sizeof(GLNode)); /*��L���գ�ΪT����һ������*/

        if (*T == NULL) {
            exit(-1);
        }

        (*T)->tag = L->tag;

        if (L->tag == ATOM) {                   /*����ԭ��*/
            (*T)->ptr.atom = L->ptr.atom;
        } else {
            CopyList(&((*T)->ptr.hp), L->ptr.hp);    /*�ݹ鸴�Ʊ�ͷ*/
        }

        if (L->tp == NULL) {
            (*T)->tp = L->tp;
        } else {
            CopyList(&((*T)->tp), L->tp);    /*�ݹ鸴�Ʊ�β*/
        }
    }
}
