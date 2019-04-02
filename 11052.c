#include<stdio.h>
#include<algorithm>
using namespace std;
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
		for(int j=1;j<=i;j++)
		{
			int tmp = dp[i-j]+digit[j];
			if(dp[i]<tmp)
				dp[i]=tmp;
		}
		//dp[i]=max(digit[i],dp[i-1]+digit[1]);
	}
	printf("%d\n", dp[n]);
}
