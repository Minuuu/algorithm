#include<stdio.h>
int coin[6]={500,100,50,10,5,1};
int main()
{
    int n;
    scanf("%d", &n);
    n = 1000 - n;
    int cnt = 0;
    int idx = 0;
    while(n>0){
        cnt+=n/coin[idx];
        n = n%coin[idx++];
    }
    printf("%d\n", cnt);
    return 0;
}
