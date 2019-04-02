#include<stdio.h>
long long dp[1001][1001];
int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0||j==i)
				dp[i][j]=1;
			else
				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%10007;
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	*/
	printf("%d\n", dp[n][k]);
	return 0;
}
