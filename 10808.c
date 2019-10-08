#include<stdio.h>
#include<string.h>
char alp[26];
int main()
{
    char s[101];
    scanf("%s", s);
    for(int i=0;i<strlen(s);i++){
        alp[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        printf("%d ", alp[i]);
    }
    return 0;
}