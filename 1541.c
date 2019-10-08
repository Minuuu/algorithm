#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str[51]={0,};
    scanf("%s", str);
    char ans[51];
    int idx = 0;
    char op = '+';
    int sum=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]>='0'&&str[i]<='9')
            ans[idx++]=str[i];
        if(str[i]=='-'||str[i]=='+'||i==strlen(str)-1){
            if(op=='+')
                sum+=atoi(ans);
            else if(op=='-')
                sum-=atoi(ans);
            if(str[i]=='-')
                op = '-';
            memset(ans,0,sizeof(ans));
            idx = 0;
        }
    }
    printf("%d\n", sum);
    return 0;
}
