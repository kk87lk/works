#include<stdio.h>
int main()
{
	int a[105],b[105],a1[105],b1[105];
	int x,y,z,i=0,m,flag=0,count=0;
	while (scanf("%d%d",&x,&y)){
        a[x]=y;
        if (x==0) break;
    }
    while (scanf("%d%d",&x,&y)){
        b[x]=y;
        if (x==0) break;
    }
	for(i=0;i<100;i++)
	{
		if(a[i]==0) 
		{
		m=i;
		break;
		}
	}
	for(i=0;i<=m;i++)
	{
		if(a[i]==0)printf("%d",b[i]);
		else if(b1[i]==0)printf("");
		else if(a[i]==1)printf("%dx+",b[i]);
		else printf("%dx%d+",b[i],a[i]);
	}
}
