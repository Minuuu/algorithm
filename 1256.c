#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
long long dp[201][201];
#define MAX 2000000000
int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= 200; i++)
	{
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			if (dp[i][j] > MAX)
				dp[i][j] = MAX + 1;
		}
	}
	int tot = n + m;
	if (dp[tot][m] < k)
	{
		printf("-1\n");
	}
	else {
		for (int i = 0; i < tot; i++)
		{
			
			if (dp[n + m - 1][m] < k) {
				printf("z");
				k -= dp[n + m - 1][m];
				m--;
			}
			else {
				printf("a");
				n--;
			}
		}
	}
	return 0;
}
