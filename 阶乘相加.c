#include<stdio.h>
#include<math.h>
int mult(int n)//º¯Êý 
{
	int i,re=1;
	for(i=1;i<=n;i++)
	{
		re=re*i;
	}	
	return re; 
 } 
 
 void main()
 {
 	int S,n,x;
 	scanf("%d",&n);  //ÊäÈënÊý 
 	for(x=1;x<=n;x++) 
 	{
		S=S+mult(x);
	}
 	printf("%d",S);
  } 
