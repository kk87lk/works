#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	int m;
	m=a>b?a:b;
	return m;
 } 
int min(int a,int b)
{
	int n;
	n=a<b?a:b;
	return n;
}

int main(void)
{
	int i,sum=0,ma,mi,sco;
	int a[10],b[10],c[10];
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	memcpy(b,a,sizeof(int)*10);
	memcpy(c,a,sizeof(int)*10);
	for(i=0;i<10;i++)
	{
		b[i+1]=max(b[i],b[i+1]);
	}
	for(i=0;i<10;i++)
	{
		c[i+1]=min(c[i],c[i+1]);
	}
	for(i=0;i<10;i++)
	{
		sum+=a[i];
	}
	ma=b[9];
	mi=c[9];
	sum=sum-ma-mi;
	sco=sum/8;
	printf("score=%d",sco);	
}
