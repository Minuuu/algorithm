#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define INF 987654321
int map[17][17];
int n,p;
int dp[1 << 17];
char str[17];
int go(int idx, int cnt)
{
	if (cnt >= p)
		return 0;
	int &ret = dp[idx];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 0; i < n; i++)
	{
		if ((idx&(1 << i)))
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j) {
					if ((idx&(1 << j))==0) {
						int param = idx | (1 << j);
						ret = min(ret, go(param,cnt+1) + map[i][j]);
					}
				}
			}
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
			scanf("%d", &map[i][j]);
	}
	scanf("%s", str);
	scanf("%d", &p);
	int bit = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'Y') {
			bit |= 1 << i;
			cnt++;
		}
	}
	memset(dp, -1, sizeof(dp));
	int ans = go(bit,cnt);
	if (ans == INF)
		ans = -1;
	printf("%d\n", ans);
	
	return 0;
}
