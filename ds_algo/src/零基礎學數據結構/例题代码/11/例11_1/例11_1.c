/*����ͷ�ļ���˳�������Ͷ���*/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
#define IndexSize 20
typedef int KeyType;
typedef struct { /*Ԫ�صĶ���*/
    KeyType key;
} DataType;
typedef struct { /*˳�������Ͷ���*/
    DataType list[MaxSize];
    int length;
} SSTable;
typedef struct { /*����������Ͷ���*/
    KeyType maxkey;
    int index;
} IndexTable[IndexSize];
int SeqSearch(SSTable S, DataType x);
int BinarySearch(SSTable S, DataType x);
int SeqIndexSearch(SSTable S, IndexTable T, int m, DataType x);
int SeqSearch(SSTable S, DataType x)
/*��˳����в��ҹؼ���Ϊx��Ԫ�أ�����ҵ����ظ�Ԫ���ڱ��е�λ�ã����򷵻�0*/
{
    int i = 0;

    while (i < S.length &&
           S.list[i].key != x.key) { /*��˳���ĵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
        i++;
    }

    if (S.list[i].key == x.key) {
        return i + 1;
    } else {
        return 0;
    }
}
int BinarySearch(SSTable S, DataType x)
/*������˳������۰���ҹؼ���Ϊx��Ԫ�أ�����ҵ����ظ�Ԫ���ڱ��е�λ�ã����򷵻�0*/
{
    int low, high, mid;
    low = 0, high = S.length - 1;   /*���ô�����Ԫ�ط�Χ���½���Ͻ�*/

    while (low <= high) {
        mid = (low + high) / 2;

        if (S.list[mid].key == x.key) { /*����ҵ�Ԫ�أ��򷵻ظ�Ԫ�����ڵ�λ��*/
            return mid + 1;
        } else if (S.list[mid].key <
                   x.key) { /*���mid��ָʾ��Ԫ��С�ڹؼ��֣����޸�lowָ��*/
            low = mid + 1;
        } else if (S.list[mid].key >
                   x.key) { /*���mid��ָʾ��Ԫ�ش��ڹؼ��֣����޸�highָ��*/
            high = mid - 1;
        }
    }

    return 0;
}

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
void main()
{
    SSTable S1 = {{123, 23, 34, 6, 8, 355, 32, 67}, 8};
    SSTable S2 = {{11, 23, 32, 35, 39, 41, 45, 67}, 8};
    SSTable S3 = {{6, 12, 23, 16, 21, 26, 41, 32, 37, 35, 48, 46, 49, 47, 52, 61, 59, 76, 68, 72}, 20};
    IndexTable T = {{23, 0}, {41, 5}, {52, 10}, {76, 15}};
    DataType x = {32};
    int pos;

    if ((pos = SeqSearch(S1, x)) != 0) {
        printf("˳���Ĳ��ң��ؼ���32�������е�λ���ǣ�%2d\n", pos);
    } else {
        printf("����ʧ�ܣ�\n");
    }

    if ((pos = BinarySearch(S2, x)) != 0) {
        printf("�۰���ң��ؼ���32�������е�λ���ǣ�%2d\n", pos);
    } else {
        printf("����ʧ�ܣ�\n");
    }

    if ((pos = SeqIndexSearch(S3, T, 4, x)) != 0) {
        printf("����˳���Ĳ��ң��ؼ���32�������е�λ���ǣ�%2d\n", pos);
    } else {
        printf("����ʧ�ܣ�\n");
    }

}