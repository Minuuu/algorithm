#include<stdio.h>
int dp[101][51];
int arr[101];
int n,m;
int main()
{
    scanf("%d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", arr+i);
    }
    printf("%d", solve(1,m));
    return 0;
}