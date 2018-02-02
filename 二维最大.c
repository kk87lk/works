#include<stdio.h>
int max(int a,int b)
{
	int m;
	m=a>b?a:b;
	return m;
 } 
 

int main(void)
{
	int i,m,c,d;
	int a[3] [4]={{1,2,3,4},{2,8,4,5},{4,5,6,7}};
	int max=a[0][0];
	for (i=0;i<3;i++)
	{
			for(m=0;m<4;m++)
			if (max<=a[i][m])
			max=a[i][m];
			c=i;
			d=m;
			
	}
	printf ("ÐÐ%dÁÐ%d",c,d);
}

