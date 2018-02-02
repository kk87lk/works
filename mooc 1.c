#include<stdio.h>
int IsPrime(int x)
{
	if(x==1)
	return 0;
	if(x==2)
	return 1;
	int i;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return 0;
	} 
	return 1;
}
int main(void)
{
	int x,i,y,m;
	scanf("%d",&x);
	y=x;
	printf("%d=",x);
	if(IsPrime(x)==1)
		printf("%d",x);
	else 
	{
		for(i=2;i<y;)
		{
			if(y%i==0)
			{
				printf("%dx",i);
				m=i;
				y=y/i;
			}
			else i++;
		}
	
			printf("%d",i);
		
	}
}
