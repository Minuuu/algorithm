#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n;
int w[17][17];
int dp[17][1 << 17];
#define INF 987654321
int go(int idx, int visit)
{
	if (visit == (1 << n) - 1)
	{
		if (w[idx][0] != 0)
			return w[idx][0];
		return INF;
	}
		
	int &ret = dp[idx][visit];
	
	if (ret != -1)
		return ret;
	ret = INF;

	for (int i = 0; i < n; i++)
	{
		if ((visit & (1 << i))==0 && w[idx][i] != 0) {
			int param = visit | (1 << i);
			ret = min(ret, go(i, param) + w[idx][i]);
		}
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &w[i][j]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 1));
	return 0;
}
