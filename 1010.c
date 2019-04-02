#include<stdio.h>
#include<string.h>
int N, M,T;
int dp[31][31];
int main()
{
	scanf("%d", &T);
	while(T--){
		memset(dp,0,sizeof(dp));
		scanf("%d %d", &N, &M);
		for(int i=0;i<=N;i++)
			dp[1][i]=1;
		for(int i=2;i<=M;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(j==0||j==i)
					dp[i][j]=1;
				else
					dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			}
		}
		printf("%d\n", dp[M][N]);
	}
	return 0;
}
