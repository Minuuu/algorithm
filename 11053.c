#include<stdio.h>
#include<algorithm>
using namespace std;
int digit[1001];
int dp[1001]; //i번째를 마지막으로 뒀을때 가장긴 증가하는 부분 수열.
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &digit[i]);
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=1;
		for(int j=1;j<i;j++)
		{
			if(digit[i]>digit[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
	}
	int ans = *max_element(dp+1,dp+n+1);
	printf("%d\n", ans);
	/*
	for(int i=1;i<=n;i++)
	{
		if(max<dp[i])
			max=dp[i];
	}
	printf("%d", max);
	*/
	return 0;
}
