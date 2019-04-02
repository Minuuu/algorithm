#include<stdio.h>
int value[101];
int dp[10001];
int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &value[i]);
	}
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(value[i]<=j)
				dp[j]+=dp[j-value[i]];
		}
	}
	printf("%d\n", dp[k]);
	return 0;
}
