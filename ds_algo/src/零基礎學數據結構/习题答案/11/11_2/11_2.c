/*����ͷ�ļ���˳�������Ͷ���*/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
#define IndexSize 20
typedef int KeyType;
typedef struct { /*Ԫ�صĶ���*/
    KeyType key;
} DataType;
typedef struct { /*����������Ͷ���*/
    KeyType maxkey;
    int index;
} IndexTable[IndexSize];
typedef struct { /*˳�������Ͷ���*/
    DataType list[MaxSize];
    int length;
} SSTable;
int SeqIndexSearch(SSTable S, IndexTable T, int m, DataType x);
int SeqIndexSearch(SSTable S, IndexTable T, int m, DataType x)
/*������S�в��ҹؼ���Ϊx��Ԫ�أ�TΪ����������ҵ����ظ�Ԫ���ڱ��е�λ�ã����򷵻�0*/
{
    int i, j, bl;

    for (i = 0; i < m; i++) /*ͨ��������ȷ��Ҫ����Ԫ�����ڵĵ�Ԫ*/
        if (T[i].maxkey >= x.key) {
            break;
        }

    if (i >= m) {       /*���Ҫ���ҵ�Ԫ�ز�������˳����У��򷵻�0*/
        return 0;
    }

    j = T[i].index;     /*Ҫ���ҵ�Ԫ���ڵ�����ĵ�j��Ԫ*/

    if (i < m - 1) {    /*blΪ��j��Ԫ�ĳ���*/
        bl = T[i + 1].index - T[i].index;
    } else {
        bl = S.length - T[i].index;
    }

    while (j < T[i].index + bl)
        if (S.list[j].key ==
            x.key) { /*����ҵ��ؼ��֣��򷵻ظùؼ��������������ڵ�λ��*/
            return j + 1;
        } else {
            j++;
        }

    return 0;


}
void DispList(SSTable S)
/*�����S�е�Ԫ��*/
{
    int i;

    for (i = 0; i < S.length; i++) {
        printf("%-4d", S.list[i].key);
    }

    printf("\n");
}
void main()
{
    SSTable S = {{2, 25, 23, 16, 21, 29, 41, 32, 37, 35, 49, 46, 59, 54, 52, 61, 89, 76, 68, 72}, 20};
    IndexTable T = {{25, 0}, {41, 5}, {59, 10}, {89, 15}};
    DataType x = {52};
    int pos;
    printf("���е�Ԫ��Ϊ:\n");
    DispList(S);

    if ((pos = SeqIndexSearch(S, T, 4, x)) != 0) {
        printf("����˳���Ĳ��ң��ؼ���52�������е�λ���ǣ�%2d\n", pos);
    } else {
        printf("����ʧ�ܣ�\n");
    }

}