#include <stdio.h>          /*���������������*/
#define N 10
/*�ṹ�����ͼ��������塢��ʼ��*/
struct student {
    char* number;
    char* name;
    char sex;
    int age;
    float score;
} stu[3] = {{"06001", "Wang Chong", 'm', 22, 78.5},
    {"06002", "Li Hua", 'f', 21, 87.0},
    {"06003", "Zhang Yang", 'm', 22, 90.0}
};
void main()
{
    struct student* p;
    printf("ѧ�����������:\n");
    printf("���          ����       �Ա�    ����   �ɼ�\n");

    for (p = stu; p < stu + 3; p++) {   /*ͨ��ָ��ṹ���ָ�����ѧ����Ϣ*/
        printf("%-8s%12s%8c%8d%6d\n", p->number, p->name, p->sex, p->age, p->score);
    }
}
