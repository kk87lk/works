#include<stdio.h>
int max(int a,int b)
{
	int m;
	if(a>b)
	b=a;
	else
	a=b;
	return b;
}

int main()
{
	int x,i;
	int s[10] ;
	for (i=0;i<=9;i++)
	{
		scanf("%d",&s[i]);
	}
	for (i=0;i<=9;i++)
	{
		s[i+1]=max(s[i],s[i+1]);
	}
	printf("%d",s[9]);
}
