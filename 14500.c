#include<stdio.h>
int N,M;
int map[501][501];
bool visit[501][501];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int max=0;
void fuck()
{
	int sum=0;
	for(int i=1;i<=N-1;i++)
	{
		for(int j=2;j<=M-1;j++)
		{
			sum=map[i][j]+map[i+1][j-1]+map[i+1][j]+map[i+1][j+1];
			if(max<sum)
				max=sum;
		}
	}

	for(int i=1;i<=N-2;i++)
	{
		for(int j=1;j<=M-1;j++)
		{
			sum=map[i][j]+map[i+1][j+1]+map[i+1][j]+map[i+2][j];
			if(max<sum)
				max=sum;
		}
	}
	for(int i=1;i<=N-1;i++)
	{
		for(int j=1;j<=M-2;j++)
		{
			sum=map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j+1];
			if(max<sum)
				max=sum;
		}
	}
	for(int i=1;i<=N-2;i++)
	{
		for(int j=2;j<=M;j++)
		{
			sum=map[i][j]+map[i+1][j-1]+map[i+1][j]+map[i+2][j];
			if(sum>max)
				max=sum;
		}
	}

}
void dfs(int a, int b, int cnt, int sum)
{
	if(cnt==4){
		if(max<sum)
			max=sum;
		return ;	
	}
	for(int i=0;i<4;i++)
	{
		int nx = a+dir[i][0];
		int ny = b+dir[i][1];
		if(nx>0&&ny>0&&nx<=N&&ny<=M){
			if(visit[nx][ny]==0){
				visit[nx][ny]=1;
				dfs(nx,ny,cnt+1,sum+map[nx][ny]);
				visit[nx][ny]=0;
			}
		}
	}

}
int main()
{
	scanf("%d %d", &N, &M);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			scanf("%d", &map[i][j]);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++){
			visit[i][j]=1;
			dfs(i,j,1,map[i][j]);
			visit[i][j]=0;
		}
	}
	fuck();
	printf("%d", max);
	return 0;
}
