#include<stdio.h>
int map[1030][1030];
int dp[1030][1030];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = map[i][1];
		for (int j = 2; j <= n; j++)
		{
			dp[i][j] = dp[i][j - 1] + map[i][j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int sum = 0;
		for (int j = x1; j <= x2; j++)
		{
			sum+=dp[j][y2] - dp[j][y1 - 1];
		}
		printf("%d\n", sum);
	}
	return 0;
}
