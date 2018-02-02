#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i;
    scanf("%s",s);//输入为字符串。
    i = strlen(s)-1;//找到字符串结尾位置。
    while(i>=0) 
    {
        printf("%c", s[i--]);
    }//逆序输出每位的值。
    
    return 0;
}
