#include<stdio.h>
int digit[1001];
int dp[1001];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &digit[i]);
	dp[1]=digit[1];
	for(int i=2;i<=n;i++)
	{
		int tmp=0;
		for(int j=1;j<i;j++)
		{
			if(digit[i]>digit[j])
			{
				if(tmp<dp[j])
					tmp=dp[j];
			}
		}
		dp[i]=tmp+digit[i];
	}
	int max=-1;
	for(int i=1;i<=n;i++)
	{
		if(max<dp[i])
			max=dp[i];
	}
	printf("%d", max);
	return 0;
}
