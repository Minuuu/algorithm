#include<stdio.h>
#include<string.h>
int T,N,K;
int map[9][9];
int visit[9][9];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int max=-1;
int ans=-1;
void solve(int x, int y, int cnt, int flag)
{
	//printf("%d %d\n", x, y);
	for(int i=0;i<4;i++)
	{
		int nx = x+dir[i][0];
		int ny = y+dir[i][1];
		if(nx>=1&&nx<=N&&ny>=1&&ny<=N&&visit[nx][ny]==0){
			if(map[nx][ny]<map[x][y])
			{
				visit[nx][ny]=1;
				solve(nx,ny,cnt+1,flag);
				visit[nx][ny]=0;
			}
			else if(map[nx][ny]>=map[x][y]&&!flag){
				if(map[nx][ny]-map[x][y]<K)
				{
					int tmp = map[nx][ny]-map[x][y]+1;
					map[nx][ny]-=tmp;
					visit[nx][ny]=1;
					solve(nx,ny,cnt+1,1);
					visit[nx][ny]=0;
					map[nx][ny]+=tmp;
				}
			}
		}
		if(ans<cnt)
			ans=cnt;
	}
	return ;
}
int main()
{
	scanf("%d", &T);
	for(int t=1;t<=T;t++)
	{
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		ans=-1;
		max=-1;
		scanf("%d %d", &N, &K);
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				scanf("%d", &map[i][j]);
				if(map[i][j]>max)
					max=map[i][j];
			}
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(max==map[i][j]){
					visit[i][j]=1;
					solve(i,j,1,0);
					visit[i][j]=0;
		//			printf("%d\n", ans);
				}
			}
		}
		printf("#%d %d\n", t,ans);
	}
	return 0;
}
