#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[100001];
int main()
{
	int n;

	scanf("%d", &n);
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=100001;
		for(int j=1;j*j<=i;j++)
		{
			if(j*j==i)
				dp[i]=1;
			else
				dp[i]=min(dp[i],dp[j*j]+dp[i-j*j]);
		}
	}
	printf("%d", dp[n]);
	return 0;
}
