#include<stdio.h>
#include<math.h>
int HuiWen(char s[])
/*�����жϣ�����ǻ��ģ�����1�����򷵻�0*/
{
    char* start = s, *end = s + strlen(s) -
                            1; /*��ʼ��start��end���ֱ�ָ���ַ����ĵ�һ���ַ������һ���ַ�*/

    for (; end > start;
         end--, start++) /*��start��endָ����ַ����αȽϣ����*start=*end����start����ƶ���end��ǰ�ƶ�*/
        if (*start != *end) {           /*���*start��*end����ֹͣ�Ƚϲ��˳�ѭ��*/
            break;
        }

    return end <= start;            /*����ǻ��ķ���1�����򷵻�0*/
}
void main()
{
    char* s[] = {"123321", "XYZAZYX", "1232"};
    int i;

    for (i = 0; i < sizeof s / sizeof(s[0]); i++) {
        if (HuiWen(s[i]) == 1) {
            printf("�ַ���%s�ǻ���!\n", s[i]);
        } else {
            printf("�ַ���%s���ǻ���!\n", s[i]);
        }
    }
}