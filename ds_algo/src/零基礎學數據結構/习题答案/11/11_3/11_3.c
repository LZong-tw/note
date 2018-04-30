#include<stdio.h>
#include<malloc.h>
#define MaxSize 20
typedef struct Node {   /*��ϣ�������Ͷ���*/
    int key;
    struct Node* next;
} HashNode;

void CreateHash(int a[], int n, int m, HashNode hash[])
/*ʹ������ַ��������ϣ��*/
{
    int i, j;
    HashNode* p;

    for (i = 0; i < m; i++) { /*��ʼ��ʱ������ͷ��next����Ϊ��*/
        hash[i].next = NULL;
    }

    for (i = 0; i < n; i++) { /*����Ԫ�ص�λ�ã������뵽��Ӧ������*/
        p = (HashNode*)malloc(sizeof(HashNode));
        p->key = a[i];
        j = (3 * a[i]) % m;
        p->next = hash[j].next;
        hash[j].next = p;
    }
}
void DispHash(HashNode hash[], int n, int m)
/*�����ϣ��*/
{
    int asl = 0, asl1;
    HashNode* p;
    int i, j;
    printf("��ϣ��Ϊ:\n");

    for (i = 0; i < m; i++) {
        printf(" %2d: ", i);
        p = hash[i].next;
        asl1 = j = 0;

        while (p != NULL) { /*�����ϣ���е�Ԫ�ز�������ҳɹ�ʱ��ƽ�����ҳ���*/
            j++;
            asl1 = asl1 + j;
            printf("%4d", p->key);
            p = p->next;
        }

        asl = asl + asl1;
        printf("\n");
    }

    printf("���ҳɹ�ʱ��ƽ�����ҳ���Ϊ:%2.3f\n", asl * 1.0 / n);
}

void main()
{
    int a[] = {34, 5, 45, 67, 21, 38, 92, 69}, n = 8, m = 11;
    HashNode hash[MaxSize];
    CreateHash(a, n, m, hash);
    DispHash(hash, n, m);
}