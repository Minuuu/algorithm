#include<stdio.h>
#include<string.h>
long long dp[1000005];
int go(int n)
{
	if(n<=2)
		return dp[n];
	long long &ret = dp[n];
	if(dp[n]!=-1)
		return ret;
	return ret = (go(n-2)+go(n-1))%15746;
}
int main()
{
	int n;
	scanf("%d", &n);
	memset(dp,-1,sizeof(dp));
	dp[1]=1;
	dp[2]=2;
	go(n);
	printf("%lld\n", dp[n]%15746);
	return 0;
}
