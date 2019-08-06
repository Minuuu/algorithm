#include<stdio.h>
#include<algorithm>
using namespace std;
int M,N;
int map[1001][1001];
int dp[1001][1001];
int solve()
{
	int cnt=0;
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(map[i][j]==0)
			{
				dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
				cnt = max(cnt,dp[i][j]);
			}
		}
	}
	return cnt;
}
int main()
{
	scanf("%d %d", &M, &N);
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	int ans = solve();
	printf("%d\n", ans);
	return 0;
}
