#include <stdio.h>
#include <string.h>
void main()
{
    int i,shuzi=0,zimu=0,kongge=0,qita=0;
    char s[100];
    gets(s);
    for(i=0;i<100;i++)
    {
        if (s[i]>='0'&&s[i]<='9')
        	shuzi++;
        else if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
        	zimu++;
        else if(s[i]==' ')
        	kongge++;
        else if(s[i]=='\0')
        	break;
        else
        	qita++;
    }
    printf("��ĸ��=%d,������=%d,�ո���=%d,������=%d",zimu,shuzi,kongge,qita);
}
