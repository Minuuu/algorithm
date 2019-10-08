#include<stdio.h>
#include<string.h>
int main()
{
    char str[101];
    scanf("%s", str);
    int ans = 1;
    for(int i=0;i<strlen(str)/2;i++){
        if(str[i]!=str[strlen(str)-i-1])
        {
            ans = 0;
            break;
        }   
    }
    printf("%d", ans);
    return 0;
}