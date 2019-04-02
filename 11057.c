#include<stdio.h>
int dp[1001][10];
int main()
{
	int n;
	long long sum=0;
	scanf("%d", &n);
	for(int i=0;i<10;i++)
	{
		dp[1][i]=1;
		sum+=dp[1][i];
	}
	long long tmp=0;
	for(int i=2;i<=n;i++)
	{
		tmp=sum;
		sum=0;
		for(int j=0;j<10;j++)
		{
			if(j!=0)
				tmp-=dp[i-1][j-1];
			dp[i][j]=tmp%10007;
	//		printf("%d ", dp[i][j]);
			sum+=dp[i][j];
		}
	//	printf("\n%d\n", sum);
	}
	long long ans=0;
	for(int i=0;i<10;i++)
	{
	//	printf("%d ", dp[n][i]);
		ans+=dp[n][i];
	}
	//printf("\n");
	printf("%ld\n", ans%10007);
	return 0;
}
