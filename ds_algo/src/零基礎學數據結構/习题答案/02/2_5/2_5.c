#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define N 30
void CopyString(char** dest, char* source, int m);

void CopyString(char** dest, char* source, int m)
/*���ַ���source�еĵ�m���Ժ���ַ����Ƶ�dest��*/
{
    int i, n;
    n = strlen(source);     /*���ַ���source�ĳ���*/
    *dest = (char*)malloc(sizeof(n - m + 2)); /*Ϊ�ַ���dest�����ڴ�ռ�*/

    for (i = m - 1; source[i] != '\0';
         i++) { /*���ַ���source�ĵ�m���Ժ���ַ����Ƶ�dest��*/
        ((*dest)[i - m + 1]) = source[i];
    }

    *(*dest + n - m + 2) = '\0'; /*���ַ���dest�������ӽ������*/

}

void main()
{
    int m = 3, a[N];
    char* source = "Hello DataSructure!", *dest;
    CopyString(&dest, source, m);
    printf("�ַ���source�еĵ�������:%s\n", source);
    printf("��source�еĵ�%d���Ժ���ַ����Ƶ�dest��dest��������:\n", m);
    printf("%s", dest);
    printf("\n");
}




