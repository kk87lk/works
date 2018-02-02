#include <stdio.h>
#include <stdlib.h>
// 这题的容易犯的错误就在于变量i不能多次运用，因为i在第一次循环后就会出问题。所以以后用变量要慎用同一变量，注意作用域 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i,j,k,cnt=0,min,m,ret,l,c;
	int a[100][100];
	int point;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	scanf("%d",&a[i][j]);	}
	}
		for(i=0;i<n;i++){
			point=a[i][0];
			ret=0;
			l=i;
			for(k=0;k<n;k++)
			{
				if(a[l][k]>point){
					point=a[l][k];
					ret=k;
				}		
			}
				min=point;
				for(c=0;c<n;c++){
					if(a[c][ret]<min)
					min=a[c][ret];	}
					if(min==point){
						cnt++;
						printf("%d %d",i,ret);
					}
			}
				
		
		if(cnt==0)
		printf("NO");
	return 0;
}
