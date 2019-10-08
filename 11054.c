#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int dp1[1001];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d", arr+i);
    
    for(int i=1;i<=n;i++){
        dp[i] = 1;
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    for(int i=n;i>=1;i--){
        dp1[i] = 1;
        for(int j=n;j>i;j--){
            if(arr[i]>arr[j]){
                dp1[i] = max(dp1[i],dp1[j]+1);
            }
        }
    }
    int ans = -1;
    for(int i=1;i<=n;i++){
        ans = max(ans,dp[i]+dp1[i]);
    }
    printf("%d\n", ans-1);
    return 0;
}