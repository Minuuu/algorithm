#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[1001];
int N;
int dp[1001];
int go(int idx)
{
	if(idx==N)
	{
		return 0;
	}
	if(idx>N)
		return 987654321;

	int &ret = dp[idx];
	if(ret!=-1)
		return ret;
	ret = 987654321;
	for(int i=1;i<=arr[idx];i++)
	{
		ret = min(ret, 1+go(idx+i));
	}

	return ret;
}
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%d", arr+i);

	memset(dp,-1,sizeof(dp));
	//dp[1]=1;
	int ans = go(1);
	if(ans==987654321)
		ans=-1;
	printf("%d\n", ans);

	return 0;
}
