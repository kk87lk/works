#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i;
    scanf("%s",s);//����Ϊ�ַ�����
    i = strlen(s)-1;//�ҵ��ַ�����βλ�á�
    while(i>=0) 
    {
        printf("%c", s[i--]);
    }//�������ÿλ��ֵ��
    
    return 0;
}
