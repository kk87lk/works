#include<stdio.h>
//void printn ( int n )
//{
//	int i;
//	for ( i=1; i<=n; i++ ){
//		printf("%d\n", i );	
//	}
//	return;
//}
void printn ( int n )
{
	if ( n ){
		printn( n - 1 );
		printf("%d\n", n );
	}
	return;
}


int main()
{
	int a=3;
	getchar();
	scanf ("%d",&a);
	printn( a );
}