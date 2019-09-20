#include<stdio.h>
#include<string.h>
int n,k;
int value[10001];
int num[101];
int dp[10001][101]; //n금액 만들때 k번째 동전까지 사용한 경우의 su
int go(int price, int idx)
{
	if(price==0)
		return 1;
	if(idx>k)
		return 0;

	int &ret = dp[price][idx];
	if(ret!=-1)
		return ret;

	ret = 0;
	for(int i=0;i<=num[idx];i++)
	{
		if(price-value[idx]*i>=0)
			ret+=go(price-value[idx]*i,idx+1);
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	scanf("%d", &k);
	for(int i=1;i<=k;i++)
		scanf("%d %d", &value[i], &num[i]);

	memset(dp,-1,sizeof(dp));
	printf("%d\n", go(n,0));
	return 0;
}
