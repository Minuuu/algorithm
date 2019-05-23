#include<stdio.h>
long long dp[41][41];
int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	int c = m-n;
	n=n+c-1;
	if(n/2<c)
		c=n-c;
//	printf("%d %d\n", n,c);
	//n-1Cr-1 + n-1Cr = nCr;
//	n=4;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==j||j==0)
				dp[i][j]=1;
			else 
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	/*
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	*/
	printf("%lld\n", dp[n][c]);
	return 0;
}
