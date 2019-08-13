#include<stdio.h>
#include<string.h>
int map[33][33];
long long dp[33][33][4];
int N=0;
int ans=0;
long long dfs(int x, int y, int type)
{
	long long &ret = dp[x][y][type];
	if(x==N&&y==N){
		return ret = 1;
	}
	if(ret!=-1)
		return ret;
	ret = 0;
	if(type==1)
	{
		y+=1;
		if(y<=N&&map[x][y]==0)
			ret += dfs(x,y,1);
		x+=1;
		if(x<=N&&y<=N&&map[x][y]==0&&map[x-1][y]==0&&map[x][y-1]==0)
			ret += dfs(x,y,3);
	}
	else if(type==2)
	{
		x+=1;
		if(x<=N&&map[x][y]==0)
			ret += dfs(x,y,2);
		y+=1;
		if(x<=N&&y<=N&&map[x][y]==0&&map[x-1][y]==0&&map[x][y-1]==0)
			ret += dfs(x,y,3);
	}
	else if(type==3)
	{
		if(x+1<=N&&y+1<=N&&map[x+1][y+1]==0&&map[x][y+1]==0&&map[x+1][y]==0)
			ret += dfs(x+1,y+1,3);
		if(x+1<=N&&map[x+1][y]==0)
			ret += dfs(x+1,y,2);
		if(y+1<=N&&map[x][y+1]==0)
			ret += dfs(x,y+1,1);
	}
	return ret;
}
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			scanf("%d", &map[i][j]);
	memset(dp,-1,sizeof(dp));
	printf("%lld", dfs(1,2,1));
	return 0;
}
