#include<stdio.h> 
void main()
{
	int a=0,b=0,c=0,x;
	for (x=100;x<=999;x++)
	{
		a=x%10;
		c=x/100;
		b=(x-a-c*100)/10;
		if(x==a*a*a+b*b*b+c*c*c)
		printf("%d\n",x);
	}
}
