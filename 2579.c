#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
int dp[301];
int stair[301];
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%d", &stair[i]);
	dp[1]=stair[1];
	dp[2]=stair[1]+stair[2];
	dp[3]=max(stair[2]+stair[3],stair[1]+stair[3]);
	for(int i=4;i<=N;i++)
	{
		dp[i]=max(dp[i-3]+stair[i-1]+stair[i],dp[i-2]+stair[i]);
	}
	printf("%d\n", dp[N]);
	return 0;
}
