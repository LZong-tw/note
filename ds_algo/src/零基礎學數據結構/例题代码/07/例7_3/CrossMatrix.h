

void InitMatrix(CrossList* M)
/*��ʼ��ϡ�����*/
{
    M->rowhead = M->colhead = NULL;
    M->m = M->n = M->len = 0;
}


void DestroyMatrix(CrossList* M)
/*����ϡ�����*/
{
    int i;
    OLink p, q;

    for (i = 0; i < M->m; i++) { /*�����ͷŽ��ռ�*/
        p = *(M->rowhead + i);

        while (p) {
            q = p;
            p = p->right;
            free(q);
        }
    }

    free(M->rowhead);
    free(M->colhead);
    InitMatrix(M);
}

void CreateMatrix(CrossList* M)
/*ʹ��ʮ������Ĵ洢��ʽ����ϡ�����*/
{
    int i, k;
    int m, n, num;
    OLNode* p, *q;

    if (M->rowhead) {       /*��������գ����ͷ�����ռ�*/
        DestroyMatrix(M);
    }

    printf("������ϡ����������,����,����Ԫ�صĸ���: ");
    scanf("%d,%d,%d", &m, &n, &num);
    M->m = m;
    M->n = n;
    M->len = num;
    M->rowhead = (OLink*)malloc(m * sizeof(OLink));

    if (!M->rowhead) {
        exit(-1);
    }

    M->colhead = (OLink*)malloc(n * sizeof(OLink));

    if (!M->colhead) {
        exit(-1);
    }

    for (k = 0; k < m; k++) { /*��ʼ��ʮ���������������ָ����Ϊ��*/
        M->rowhead[k] = NULL;
    }

    for (k = 0; k < n; k++) { /*��ʼ��ʮ���������������ָ����Ϊ��*/
        M->colhead[k] = NULL;
    }

    printf("�밴�����������%d������Ԫ���кš��кż�Ԫ��ֵ:\n", M->len);

    for (k = 0; k < num; k++) {
        p = (OLink*)malloc(sizeof(OLNode));  /*��̬���ɽ��*/

        if (!p) {
            exit(-1);
        }

        printf("�������%d������Ԫ���к�(0~%d)���к�(0~%d)��Ԫ��ֵ:", k + 1, m, n);
        scanf("%d,%d,%d", &p->i, &p->j, &p->e); /*���������кţ��кź�Ԫ��ֵ*/

        /*-----------------------------�в���p���-----------------------------------*/
        if (M->rowhead[p->i] == NULL ||
            M->rowhead[p->i]->j >
            p->j) { /*����ǵ�һ������ǰԪ�ص��к�С�ڱ�ͷָ���һ����Ԫ��*/
            p->right = M->rowhead[p->i];
            M->rowhead[p->i] = p;
        } else {
            q = M->rowhead[p->i];

            while (q->right && q->right->j < p->j) { /*�ҵ�Ҫ�������λ��*/
                q = q->right;
            }

            p->right = q->right;                /*��p���뵽q���֮��*/
            q->right = p;
        }

        /*------------------------------�в���p���-----------------------------------*/
        q = M->colhead[p->j];                   /*��qָ������������*/

        if (!q || p->i <
            q->i) {                /*���p���к�С�ڱ�ͷָ����кŻ�Ϊ�ձ���ֱ�Ӳ���*/
            p->down = M->colhead[p->j];
            M->colhead[p->j] = p;
        } else {
            while (q->down &&
                   q->down->i < p->i) { /*���q���к�С��p���кţ����������в��Ҳ���λ��*/
                q = q->down;
            }

            p->down = q->down;                  /*��p���뵽q���֮��*/
            q->down = p;
        }
    }
}

//void PrintMatrix(CrossList M)
///*ʮ����������*/
//{
//  int i,j;
//  OLink p;
//  printf("%d��%d��%d������Ԫ��\n",M.m,M.n,M.len);
//  for(j=0;j<M.m;j++)
//  {
//      p=M.rowhead[j];
//      while(p)
//      {
//          printf("%d��%d�е�ֵΪ%d\n",p->i,p->j,p->e);
//          p=p->right;
//      }
//  }
//}

void PrintMatrix(CrossList M)
/*��������ʽ���ʮ������*/
{
    int i, j;
    OLink p;

    for (i = 0; i < M.m; i++) {
        p = M.rowhead[i];           /*pָ����еĵ�1������Ԫ��*/

        for (j = 0; j < M.n; j++)   /*�ӵ�һ�е����һ�н������*/
            if (!p || p->j != j) {  /*�ѵ����б�β��ǰ������ֵ�����ڵ�ǰ��ֵ�������0*/
                printf("%-3d", 0);
            } else {
                printf("%-3d", p->e);
                p = p->right;
            }

        printf("\n");
    }
}


void InsertMatrix(CrossList* M, OLink p)
/*��������p���뵽ϡ�������*/
{
    OLink q = M->rowhead[p->i];     /*qָ������б�*/

    if (!q || p->j <
        q->j) {        /*������б�ջ�p��ָ������ֵС���׽�����ֵ����ֱ�Ӳ���*/
        p->right = M->rowhead[p->i];
        M->rowhead[p->i] = p;
    } else {
        while (q->right &&
               q->right->j < p->j) { /*q��ָ����β�����q����һ������ֵС��p��ָ������ֵ*/
            q = q->right;
        }

        p->right = q->right;
        q->right = p;
    }

    q = M->colhead[p->j];               /*qָ������б�*/

    if (!q || p->i <
        q->i) {            /*������б�ջ�p��ָ������ֵС���׽�����ֵ*/
        p->down = M->colhead[p->j];
        M->colhead[p->j] = p;
    } else {
        while (q->down &&
               q->down->i < p->i) { /*q��ָ����β�����q����һ������ֵС��p��ָ������ֵ*/
            q = q->down;
        }

        p->down = q->down;
        q->down = p;
    }

    M->len++;
}
