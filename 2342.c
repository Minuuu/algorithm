#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int lf, rf;
int dp[5][5][100005];
int arr[100001];
int getCost(int cur, int next) {
	if (cur == 0 || next == 0)
		return 2;
	else if (cur == next)
		return 1;
	else if ((cur+next)%2==0){
		return 4;
	}
	else if ((cur + next) % 2 == 1) {
		return 3;
	}
	return 0;
}
int go(int l, int r, int idx, int n) {
	if (idx == n)
		return 0;
	int &ret = dp[l][r][idx];
	if (ret != -1)
		return ret;

	int r1 = go(arr[idx], r, idx + 1, n)+getCost(l,arr[idx]);
	int r2 = go(l, arr[idx], idx + 1, n)+ getCost(r, arr[idx]);

	return ret = min(r1, r2);
}
int main()
{
	int idx = 0;
	while (1) {
		int num;
		scanf("%d", &num);
		if (num == 0)
			break;
		arr[idx++] = num;
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(lf, rf, 0,idx));
	return 0;
}
