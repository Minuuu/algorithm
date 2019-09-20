#include<stdio.h>
#include<string.h>
int map[101][101];
long long dp[101][101];
int n;
long long go(int x, int y)
{
	if(x>n||y>n)
		return 0;
	if(x==n&&y==n)
		return 1;
	long long &ret = dp[x][y];
	if(ret!=-1ll)
		return ret;
	return ret = go(x+map[x][y],y)+go(x,y+map[x][y]);
}
int main()
{
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d", &map[i][j]);
	memset(dp,-1,sizeof(dp));
	printf("%lld\n", go(1,1));

	return 0;

}
