#include<stdio.h>
int digit[1001];
int dp[1001];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &digit[i]);
	}
	dp[1]=1;
	int max=-1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=1;
		for(int j=1;j<i;j++)
		{
			if(digit[i]>digit[j])
			{
				if(dp[j]+1>dp[i])
					dp[i]=dp[j]+1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(max<dp[i])
			max=dp[i];
	}
	printf("%d", max);
	return 0;
}
