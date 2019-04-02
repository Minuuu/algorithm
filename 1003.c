#include<stdio.h>
int N,T;
struct node{
	int zero;
	int one;
};
struct node dp[41];
int main()
{
	scanf("%d", &T);
	dp[0].zero=1;
	dp[1].one=1;
	while(T--)
	{
		scanf("%d", &N);
		for(int i=2;i<=N;i++)
		{
			dp[i].zero=dp[i-1].zero+dp[i-2].zero;
			dp[i].one=dp[i-1].one+dp[i-2].one;
		}
		printf("%d %d\n", dp[N].zero, dp[N].one);
	}
	return 0;
}
