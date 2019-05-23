#include<stdio.h>
int dp[11][11];
int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0||j==i)
				dp[i][j]=1;
			else
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	printf("%d\n", dp[n][k]);
	return 0;
}
