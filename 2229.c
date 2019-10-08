#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int arr[1001];
int dp[1001];
int n;
int go(int idx){
    if(idx==n)
        return 0;
    int &ret = dp[idx];
    if(ret!=-1)
        return ret;
    
    int low = 0x3f3f3f3f;
    int high = -1;
    ret = 0;
    for(int i=idx;i<n;i++){
        low = min(arr[i],low);
        high = max(arr[i], high);
        ret = max(ret,high-low+go(i+1));
    }
    return ret;
}
int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", arr+i);
    
    memset(dp,-1,sizeof(dp));
    printf("%d", go(0));

    return 0;
}
