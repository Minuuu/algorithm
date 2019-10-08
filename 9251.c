#include<stdio.h>
#include<string.h>
#include<algorithm>
char c1[1005];
char c2[1005];
int dp[1005][1005];
using namespace std;
int main()
{
	scanf("%s", c1+1);
	scanf("%s", c2+1);
	int len1 = strlen(c1+1);
	int len2 = strlen(c2+1);
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			if(c1[i]==c2[j])
			{
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d\n", dp[len1][len2]);
	return 0;
}
