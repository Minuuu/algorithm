#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
//int value[101];
int dp[10001];
vector<int> value;
int main()
{
	int n,k;
	int num;
	scanf("%d %d", &n, &k);
	value.push_back(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &num);
		value.push_back(num);
	}
	sort(value.begin(),value.end());
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(value[i]<=j)
			{
				if(j%value[i]==0)
				{
					dp[j]=j/value[i];
				}
				else{
					if(dp[j-value[i]]!=0){
						if(dp[j]==0)
							dp[j]=dp[j-value[i]]+1;
						else
							dp[j]=min(dp[j],dp[j-value[i]]+1);
					}
				}
			}
		}
	}
	if(dp[k]==0)
		dp[k]=-1;
	printf("%d\n", dp[k]);
	return 0;
}
