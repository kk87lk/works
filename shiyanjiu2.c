#include<stdio.h>
#include<math.h>
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
int IsSuperPrime(int x)
{
	int i;
	do
	{
		
		if(IsPrime(x)!=1)
		return 0;
		x=x/10;
	}while(x>0);	
	return 1;
}
int main(void)
{
	int x;
	for(x=113;x<=10000;x++)
	{
		if(IsSuperPrime(x)==1)
		printf("%d ",x);
	}
	
}
