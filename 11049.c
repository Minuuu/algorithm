#include<stdio.h>
#include<vector>
#include<string.h>
#include<limits.h>
#include<algorithm>
using namespace std;
vector<pair<int, int>> v;
int dp[505][505];
#define MAX 987654321
int go(int left, int right)
{
	if (left == right)
		return 0;
	int &ret = dp[left][right];
	if (ret != -1)
		return ret;
	ret = MAX;
	for (int i = left; i <= right; i++)
		ret = min(ret, go(left, i) + go(i + 1, right) + v[left].first*v[i].second*v[right].second);
	return ret;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, n - 1));
	return 0;
}
