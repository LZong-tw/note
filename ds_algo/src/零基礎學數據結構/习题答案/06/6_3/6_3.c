#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MaxLength 60

char* strcpy2(char* strDest, const char* strSrc)
/*�ַ�������������ʵ��*/
{
    char* strDestCopy;

    if ((strDest == '\0') || (strSrc == '\0')) {
        return;
    }

    strDestCopy = strDest;          /*�����ַ������׵�ַ*/

    while ((*strDest++ = *strSrc++) != '\0');

    return strDestCopy;
}
int strcmp2(const char* dest, const char* source)
/*�ַ����ȽϺ�����ʵ��*/
/*���dest��ֵ����source,�򷵻�ֵ����0�����dest��ֵ����source,�򷵻�ֵ����0�����dest��ֵС��source ,�򷵻�ֵС��0*/
{
    if ((dest != NULL) && (source != NULL)) {
        return;
    }

    while (*dest != '\0' && *source != '\0' &&
           (*dest == *source)) { /*��������ַ�����Ϊ����ֵ��ȣ�������Ƚ���һ���ַ�*/
        source++;
        dest++;
    }

    return *dest - *source;
}
void main()
{
    char strSrc[] = "acaabccaabcca";
    char strDest[MaxLength];
    char dest[] = "Hello", source[] = "Hello";
    int n, f;
    /*���������Ĳ���*/
    strcpy2(strDest, strSrc);
    printf("strDest�ַ���Ϊ:", n);
    puts(strDest);
    n = strlen(strcpy2(strDest, strSrc));
    printf("strDest�ĳ�����:%2d\n", n);
    /*�ȽϺ����Ĳ���*/
    printf("dest�ַ���Ϊ:");
    puts(dest);
    printf("source�ַ���Ϊ");
    puts(source);
    f = strcmp2(dest, source);

    if (f == 0) {
        printf("dest��ֵ����source\n");
    } else if (f < 0) {
        printf("dest��ֵ����source\n");
    } else {
        printf("dest��ֵ����source\n");
    }

}

