
typedef struct {
    DataType stack[StackSize];
    int top[2];
} SSeqStack;


void InitStack(SSeqStack* S)
/*����ջ�ĳ�ʼ������*/
{
    S->top[0] = 0;
    S->top[1] = StackSize - 1;
}
int PushStack(SSeqStack* S, DataType e, int flag)
/*����ջ��ջ��������ջ�ɹ�����1�����򷵻�0*/
{
    if (S->top[0] == S->top[1]) {   /*�ڽ�ջ����֮ǰ���жϹ���ջ�Ƿ�Ϊ��*/
        return 0;
    }

    switch (flag) {
    case 0:             /*��flagΪ0����ʾԪ��Ҫ����˵�ջ*/
        S->stack[S->top[0]] = e; /*Ԫ�ؽ�ջ*/
        S->top[0]++;            /*�޸�ջ��ָ��*/
        break;

    case 1:             /*��flagΪ1����ʾԪ��Ҫ���Ҷ˵�ջ*/
        S->stack[S->top[1]] = e; /*Ԫ�ؽ�ջ*/
        S->top[1]--;            /*�޸�ջ��ָ��*/
        break;

    default:
        return 0;
    }

    return 1;
}
int PopStack(SSeqStack* S, DataType* e, int flag)
{
    switch (flag) {         /*�ڳ�ջ����֮ǰ���ж����ĸ�ջҪ���г�ջ����*/
    case 0:
        if (S->top[0] == 0) { /*��˵�ջΪ�գ��򷵻�0����ʾ��ջ����ʧ��*/
            return 0;
        }

        S->top[0]--;        /*�޸�ջ��ָ��*/
        *e = S->stack[S->top[0]]; /*����ջ��Ԫ�ظ�ֵ��e*/
        break;

    case 1:
        if (S->top[1] == StackSize - 1) { /*�Ҷ˵�ջΪ�գ��򷵻�0����ʾ��ջ����ʧ��*/
            return 0;
        }

        S->top[1]++;                /*�޸�ջ��ָ��*/
        *e = S->stack[S->top[1]]; /*����ջ��Ԫ�ظ�ֵ��e*/
        break;

    default:
        return 0;
    }

    return 1;
}
