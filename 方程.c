#include <stdio.h>
#include <math.h>
int main() 
{
int a,b,c,x1,x2;
printf ("ax^2+bx+c=0 ������a b c\n");
scanf  ("%d %d %d",&a,&b,&c);
x1=(-b+sqrt(b*b-4*a*c))/(2*a);
x2=(-b-sqrt(b*b-4*a*c))/(2*a);
printf ("x1=%f\nx2=%f",x1,x2);
return 0;
}
