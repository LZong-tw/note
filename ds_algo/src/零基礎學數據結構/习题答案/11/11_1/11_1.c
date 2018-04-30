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
int BinarySearch(SSTable S, DataType x);
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
int BinarySearch2(SSTable S, int low, int high, DataType x)
/*�ݹ�ʵ���۰����*/
{
    int mid;

    if (low < high) {
        mid = (low + high) / 2;

        if (S.list[mid].key == x.key) { /*����ҵ�Ԫ�أ��򷵻ظ�Ԫ�����ڵ�λ��*/
            return mid + 1;
        } else if (S.list[mid].key >
                   x.key) { /*���mid��ָʾ��Ԫ��С�ڹؼ��֣����ڱ���ϰ벿�ֲ���*/
            return BinarySearch2(S, low, mid - 1, x);
        } else {                        /*���mid��ָʾ��Ԫ�ش��ڹؼ��֣����ڱ���°벿�ֲ���*/
            return BinarySearch2(S, mid + 1, high, x);
        }
    }

    return 0;

}
void DispList(SSTable S)
{
    int i;

    for (i = 0; i < S.length; i++) {
        printf("%4d", S.list[i].key);
    }

    printf("\n");
}
void main()
{
    SSTable S = {{12, 23, 34, 43, 49, 67, 78, 98}, 8};
    DataType x = {67};
    int pos;
    printf("��S�е�Ԫ��Ϊ��\n");
    DispList(S);

    if ((pos = BinarySearch(S, x)) != 0) {
        printf("�ǵݹ�ʵ���۰���ң��ؼ���67�ڱ��е�λ���ǣ�%2d\n", pos);
    } else {
        printf("����ʧ�ܣ�\n");
    }

    if ((pos = BinarySearch2(S, 0, 7, x)) != 0) {
        printf("�ݹ�ʵ���۰���ң��ؼ���67�ڱ��е�λ���ǣ�%2d\n", pos);
    } else {
        printf("����ʧ�ܣ�\n");
    }

}