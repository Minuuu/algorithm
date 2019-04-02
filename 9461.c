#include<stdio.h>
#include<string.h>
long long dp[101];
int main()
{
	int n,T;
	scanf("%d", &T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d", &n);
		dp[1]=1;
		dp[2]=1;
		dp[3]=1;
		dp[4]=2;
		dp[5]=2;
		for(int i=6;i<=n;i++)
			dp[i]=dp[i-1]+dp[i-5];
		printf("%ld\n", dp[n]);
	}
	return 0;
}
