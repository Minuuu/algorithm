#include<stdio.h>
#include<algorithm>
using namespace std;
int map[1001][1001];

int main()
{
	int n, m;
	int ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j]) {
				map[i][j] = min(map[i - 1][j - 1], min(map[i - 1][j], map[i][j - 1])) + 1;
				ans = max(ans, map[i][j]);
			}
		}
	}
	printf("%d", ans*ans);
	return 0;
}
