#include<stdio.h>
#include<string.h>
#include<queue>
int N,M;
int map[9][9];
int copy[9][9];
int tmp[9][9];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int a, int b)
{
	for(int i=0;i<4;i++)
	{
		int nx = a+ dir[i][0];
		int ny = b+ dir[i][1];
		if(nx>0&&nx<=N&&ny>0&&ny<=M&&tmp[nx][ny]==0){
			tmp[nx][ny]=2;
			dfs(nx,ny);
		}
	}
	
}
int max=0;
void makeWall(int cnt)
{
	if(cnt==3){
		int safe=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
				tmp[i][j]=copy[i][j];
		}
		/*
		printf("1####\n");
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
				printf("%d ", tmp[i][j]);
			printf("\n");
		}
		*/
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				if(copy[i][j]==2){
					dfs(i,j);
				}
			}
		}
		//printf("2####\n");
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
		//		printf("%d ", tmp[i][j]);
				if(tmp[i][j]==0)
					safe++;
			}
		//	printf("\n");
		}
		//printf("safe: %d\n", safe);
		if(max<safe)
			max=safe;
		return ;
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(copy[i][j]==0){
				copy[i][j]=1;
			//	printf("%d %d\n", i,j);
				makeWall(cnt+1);
				copy[i][j]=0;
			}
		}
	}
}
void copyMap()
{
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			copy[i][j]=map[i][j];
}
int main()
{
	scanf("%d %d", &N,&M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
			scanf("%d", &map[i][j]);
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(map[i][j]==0)
			{
				copyMap();
				copy[i][j]=1;
		//		printf("### %d %d\n", i,j);
				makeWall(1);
				copy[i][j]=0;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}
