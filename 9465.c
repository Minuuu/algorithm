#include<stdio.h>
#include<algorithm>
using namespace std;
int T;
int N;
int dp[2][100001];
int stick[2][100001];
// 인덱스를 [3][100001]; 로 잡아서 0 안붙일때 1 첫째줄 2 아래
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i=0;i<2;i++)
		{
			for(int j=1;j<=N;j++)
				scanf("%d", &stick[i][j]);
		}
		dp[0][1]=stick[0][1];
		dp[1][1]=stick[1][1];
		for(int i=2;i<=N;i++)
		{
			dp[0][i]=max(dp[1][i-1],dp[1][i-2])+stick[0][i];
			dp[1][i]=max(dp[0][i-1],dp[0][i-2])+stick[1][i];
		}
		for(int i=0;i<2;i++)
		{
			for(int j=1;j<=N;j++)
				printf("%d ", dp[i][j]);
			printf("\n");
		}
		printf("%d\n", max(dp[0][N],dp[1][N]));
	}
	return 0;
}
