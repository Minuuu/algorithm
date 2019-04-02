#include<stdio.h>
int N,M;
int dp[90001];
int main()
{
	scanf("%d %d", &N, &M);
	dp[1]=0;
	int sum=N-1+(M-1)*N;//11,
	printf("%d\n", sum);
	return 0;
}
