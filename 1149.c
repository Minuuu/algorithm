#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
int dp[1000][3];
int value[1000][3];
int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<3;j++)
			scanf("%d", &value[i][j]);
	}
	dp[0][0]=value[0][0];
	dp[0][1]=value[0][1];
	dp[0][2]=value[0][2];
	for(int i=1;i<N;i++)
	{
		dp[i][0]=min(dp[i-1][1],dp[i-1][2])+value[i][0];
		dp[i][1]=min(dp[i-1][0],dp[i-1][2])+value[i][1];
		dp[i][2]=min(dp[i-1][1],dp[i-1][0])+value[i][2];
	}
	printf("%d", min(dp[N-1][0],min(dp[N-1][1],dp[N-1][2])));
	return 0;
}
