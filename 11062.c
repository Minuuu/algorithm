#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int arr[1005];
int dp[1005][1005][2];
int go(int left, int right, int idx)
{
	if (left >= right)
	{
		if (idx == 0)
			return dp[left][right][idx] = arr[left];
		return 0;
	}
	int &ret = dp[left][right][idx];
	if (ret != -1)
		return ret;
	int r1=-1, r2=-1;
	if (idx % 2 == 0) {
		r1 = go(left + 1, right, (idx + 1) % 2) + arr[left];
		r2 = go(left, right - 1, (idx + 1) % 2) + arr[right];
		ret = max(r1, r2);
	}
	else {
		r1 = go(left + 1, right, (idx + 1) % 2);
		r2 = go(left, right - 1, (idx + 1) % 2);
		ret = min(r1, r2);
	}
	
	return ret;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		memset(arr, -1, sizeof(arr));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		memset(dp, -1, sizeof(dp));
		
		printf("%d\n", go(0, n-1,0));
	}
}
