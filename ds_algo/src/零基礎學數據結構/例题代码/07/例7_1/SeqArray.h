#define MaxArraySize 2
typedef struct {
    DataType* base;     /*����Ԫ�صĻ���ַ*/
    int dim;            /*�����ά��*/
    int* bounds;        /*�����ÿһά֮��Ľ��޵ĵ�ַ*/
    int* constants;     /*����洢ӳ��������ַ*/
} Array;

int InitArray(Array* A, int dim, ...)
/*����ĳ�ʼ������*/
{
    int elemtotal = 1, i;               /*elemtotal������Ԫ����������ֵΪ1*/
    va_list ap;

    if (dim < 1 || dim > MaxArraySize) { /*���ά�����Ϸ�������0*/
        return 0;
    }

    A->dim = dim;
    A->bounds = (int*)malloc(dim * sizeof(int)); /*����һ��dim��С���ڴ浥Ԫ*/

    if (!A->bounds) {
        exit(-1);
    }

    va_start(ap,
             dim);                  /*dim��һ���̶����������ɱ������ǰһ������*/

    for (i = 0; i < dim; ++i) {
        A->bounds[i] = va_arg(ap, int);     /*����ȡ�ÿɱ����������ά�ĳ���*/

        if (A->bounds[i] < 0) {
            return -1;    // ��math.h�ж���Ϊ4
        }

        elemtotal *= A->bounds[i];          /*�õ�������Ԫ���ܵĸ���*/
    }

    va_end(ap);
    A->base = (DataType*)malloc(elemtotal * sizeof(
                                    DataType)); /*Ϊ�����������Ԫ�ط����ڴ�ռ�*/

    if (!A->base) {
        exit(-1);
    }

    A->constants = (int*)malloc(dim * sizeof(int)); /*Ϊ����ĳ�����ַ�����ڴ浥Ԫ*/

    if (!A->constants) {
        exit(-1);
    }

    A->constants[dim - 1] = 1;

    for (i = dim - 2; i >= 0; --i) {
        A->constants[i] = A->bounds[i + 1] * A->constants[i + 1];
    }

    return 1;
}
void DestroyArray(Array* A)
/*�������顣����̬������ڴ浥Ԫ�ͷ�*/
{
    if (A->base) {
        free(A->base);
    }

    if (A->bounds) {
        free(A->bounds);
    }

    if (A->constants) {
        free(A->constants);
    }

    A->base = A->bounds = A->constants = NULL;  /*������ָ��ָ���*/
    A->dim = 0;
}
int GetValue(DataType* e, Array A, ...)
/*����������ָ����Ԫ�أ���ָ����������±��Ԫ�ظ�ֵ��e*/
{
    va_list ap;
    int offset;
    va_start(ap, A);

    if (LocateArray(A, ap, &offset) == 0) { /*�ҵ�Ԫ���������е����λ��*/
        return 0;
    }

    va_end(ap);
    *e = *(A.base + offset);        /*��Ԫ��ֵ��ֵ��e*/
    return 1;
}
int AssignValue(Array A, DataType e, ...)
/*����ĸ�ֵ��������e��ֵ������ָ��������Ԫ��*/
{
    va_list ap;
    int offset;
    va_start(ap, e);

    if (LocateArray(A, ap, &offset) == 0) { /*�ҵ�Ԫ���������е����λ��*/
        return 0;
    }

    va_end(ap);
    *(A.base + offset) = e;         /*��e��ֵ����Ԫ��*/
    return 1;
}
int LocateArray(Array A, va_list ap, int* offset)
/*����������Ԫ�ص��±꣬�����Ԫ����A�е���Ե�ַoffset*/
{
    int i, instand;
    *offset = 0;

    for (i = 0; i < A.dim; i++) {
        instand = va_arg(ap, int);

        if (instand < 0 || instand >= A.bounds[i]) {
            return 0;
        }

        *offset += A.constants[i] * instand;
    }

    return 1;
}
