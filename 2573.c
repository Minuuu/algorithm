#include<stdio.h>
#include<string.h>
int map[301][301];
int visit[301][301];
int update[301][301];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
void dfs(int x, int y)
{
	visit[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int nx = x+dir[i][0];
		int ny = y+dir[i][1];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m){
			if(visit[nx][ny]==0&&map[nx][ny]>0)
				dfs(nx,ny);
		}
	}
}
void melt()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(map[i][j]>0){
				for(int k=0;k<4;k++)
				{
					int x = i+dir[k][0];
					int y = j+dir[k][1];
					if(x>=1&&x<=n&&y>=1&&y<=m)
					{
						if(map[x][y]==0){
							update[i][j]++;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			map[i][j]-=update[i][j];
			if(map[i][j]<0)
				map[i][j]=0;
		}
	}
}
void print(int arr[301][301])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d", &map[i][j]);

		}
	}
	int time=0;
	int cnt=0;
	while(1)
	{
		cnt=0;
		memset(visit,0,sizeof(visit));
		memset(update,0,sizeof(update));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(visit[i][j]==0&&map[i][j]>0){
					dfs(i,j);
					cnt++;
				}
				if(cnt>=2)
					break;
			}
			if(cnt>=2)
				break;
		}
		if(cnt==0)
		{
			time=0;
			break;
		}
		if(cnt>=2)
			break;
		time++;
		melt();
	//	print(map);
	//	print(update);
	}
	printf("%d\n", time);
	return 0;
}
