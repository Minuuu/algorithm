#include<stdio.h>
int map[17][17];
int visit[17][17];
int N=0;
int ans=0;
void dfs(int x, int y, int type)
{
	if(x==N&&y==N){
		ans++;
		return ;
	}
	if(type==1)
	{
		y+=1;
		if(y<=N&&map[x][y]==0)
			dfs(x,y,1);
		x+=1;
		if(x<=N&&y<=N&&map[x][y]==0&&map[x-1][y]==0&&map[x][y-1]==0)
			dfs(x,y,3);
	}
	else if(type==2)
	{
		x+=1;
		if(x<=N&&map[x][y]==0)
			dfs(x,y,2);
		y+=1;
		if(x<=N&&y<=N&&map[x][y]==0&&map[x-1][y]==0&&map[x][y-1]==0)
			dfs(x,y,3);
	}
	else if(type==3)
	{
		if(x+1<=N&&y+1<=N&&map[x+1][y+1]==0&&map[x][y+1]==0&&map[x+1][y]==0)
			dfs(x+1,y+1,3);
		if(x+1<=N&&map[x+1][y]==0)
			dfs(x+1,y,2);
		if(y+1<=N&&map[x][y+1]==0)
			dfs(x,y+1,1);
	}
}
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			scanf("%d", &map[i][j]);

	dfs(1,2,1);
	printf("%d\n", ans);
	return 0;
}
