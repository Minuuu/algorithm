#include<stdio.h>
#include<string.h>
int N,M;
int map[501][501];
int dp[501][501];
int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
int solve(int x, int y)
{
	//printf("%d\n", map[x][y]);
	int &ret = dp[x][y];
	if(ret!=-1)
		return ret;
	if(x==N-1&&y==M-1)
		return ret=1;

	ret = 0;
	for(int i=0;i<4;i++)
	{
		int nx = dir[i][0]+x;
		int ny = dir[i][1]+y;
		if(nx>=0&&nx<N&&ny>=0&&ny<M)
		{
			if(map[x][y]>map[nx][ny])
			{
				ret += solve(nx,ny);
			}
		}
	}
	return ret;
}
int main()
{
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			scanf("%d", &map[i][j]);
	}
	memset(dp,-1,sizeof(dp));
	int ret = solve(0,0);
	printf("%d", ret);
	//printf("%d", dp[N-1][M-1]);
	return 0;
}
