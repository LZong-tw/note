#include<stdio.h>
#include<math.h>

int Distribute(int n)
/*��������ĸ�λ����*/
{
    int j, c;

    if (n >= 10) {      /*���n��λ��������λ������ִ��n/10�����n�ĸ�λ����*/
        Distribute(n / 10);
    }

    printf("%3d", n % 10); /*���n�����һλ����*/

}

void main()
{
    int n = 4567;
    printf("����%d�ĸ�λ������:", n);
    Distribute(n);
    printf("\n");
}