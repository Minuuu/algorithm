#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int arr[205];
int dp[205][205];
int go(int x, int y) {
	if (x == y)
		return 0;
	int &ret = dp[x][y];
	if (ret != -1)
		return ret;
	ret = 987654321;
	for (int i = x; i < y; i++) {
		int flag = 0;
		if (arr[x] != arr[i + 1]) {
			flag = 1;
		}
		ret = min(ret, go(x, i) + go(i + 1, y) + flag);
	}
	return ret;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0,n-1));
	return 0;
}
