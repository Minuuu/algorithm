#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[501][501];
int digit[501][501];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d", &digit[i][j]);
	dp[1][1]=digit[1][1];
	for(int i=2;i<=n;i++)
	{
		dp[i][1]=dp[i-1][1]+digit[i][1];
		dp[i][i]=dp[i-1][i-1]+digit[i][i];
		for(int j=2;j<i;j++)
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+digit[i][j];
	}
	int res=-1;
	for(int i=1;i<=n;i++)
		if(res<dp[n][i])
			res=dp[n][i];
	printf("%d\n", res);
	return 0;
}
