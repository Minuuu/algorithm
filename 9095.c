#include<stdio.h>
int T,N;
int dp[12];
int solve(int n)
{
	if(n<4){
		return dp[n];
	}
	return solve(n-1)+solve(n-2)+solve(n-3);
}
int main()
{
	scanf("%d", &T);
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	while(T--)
	{
		scanf("%d", &N);
		printf("%d\n", solve(N));
	}
}
