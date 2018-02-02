#include<stdio.h>
#include<string.h>
int main()
{
	int x;
	char s[1000];
	gets(s);
	x=strlen(s);
	int i,count=0;
	for(i=0;i<x;i++)
	{
		if(s[0]!=' ')
			count++;
		if(i>0)
		{
			if(s[i]!=' '&&s[i]!='.')
			count ++;
		if(s[i]==' ')
		{
			if(s[i]==' '&&s[i-1]!=' ')
			{
			printf("%d ",count);
			count=0;
			}
		}	
		if(s[i]=='.'&&s[i-1]!=' ')
		{
			printf("%d",count);
			count=0;
		}
				}		
	}
 } 
