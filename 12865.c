#include<stdio.h>
#include<algorithm>
using namespace std;
int w[100001];
int v[1001];
int dp[2][100001];//무게에 따른 가치의 합
int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d", w+i, v+i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(j>=w[i])
				dp[i%2][j] = max(dp[(i-1)%2][j],dp[(i-1)%2][j-w[i]]+v[i]);
			else
				dp[i%2][j] = dp[(i-1)%2][j];
		}
	}
	printf("%d\n", dp[n%2][k]);
	return 0;
}
