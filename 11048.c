#include<stdio.h>
#include<algorithm>
using namespace std;
int N,M;
int map[1001][1001];
int dp[1001][1001];
int main()
{
	scanf("%d %d", &N, &M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+map[i][j];
		}
	}
	printf("%d\n", dp[N][M]);
	return 0;
}
