#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	long long num[100001];
	long long dp[100001];
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%ld", &num[i]);
	dp[1]=num[1];
	for(int i=2;i<=n;i++)
		dp[i]=max(num[i],dp[i-1]+num[i]);
	printf("%ld\n", *max_element(dp+1,dp+n+1));
	return 0;
}
