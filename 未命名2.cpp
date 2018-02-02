#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Prime(int y)
{	if(y==0||y==1)
	return 0;
	int i,isPrime=1;
	for(i=2;i<=sqrt(y);i++)
	{
		if(y%i==0)
		{	isPrime=0;
			break;
		}
	}return isPrime;
}
int main(int argc, char *argv[]) {
	int x,ret,i,t=1,d;
	scanf("%d",&x);
	if(x==0||x==1)
	printf("%d=%d",x,x);
	else{
		printf("%d=",x);
		ret=Prime(x);
	if(ret)
	printf("%d",x);
	else{	for(i=2;x>1;){
				d=x%i;
				if(d==0)
				{
					printf("%d",i);
					t=x/i;
					x=t;
					if(x!=1)
					printf("x");
					
				}
					else i++;
							}
		}
	}
	
	return 0;
}

