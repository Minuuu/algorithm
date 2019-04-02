#include<stdio.h>
#include<string.h>
int N;
int map[101][101];
bool visit[101][101];
int cnt=0;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,-0}};
void dfs(int a, int b, int lvl)
{
	visit[a][b]=1;
	for(int i=0;i<4;i++)
	{
		int nx = a+dir[i][0];
		int ny = b+dir[i][1];
		if(nx>0&&nx<=N&&ny>0&&ny<=N&&visit[nx][ny]==0&&map[nx][ny]>lvl){
	//		printf("%d, %d\n", nx, ny);
			dfs(nx,ny,lvl);
		}
	}
}
int main()
{
	int max=0;
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++){
			scanf("%d", &map[i][j]);
			if(max<map[i][j])
				max=map[i][j];
		}
	}
	int cntMax=1;
	for(int i=1;i<=max;i++)
	{
		memset(visit,0,sizeof(visit));
		cnt=0;
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=N;k++)
			{
				if(visit[j][k]==0&&map[j][k]>i)
				{
					dfs(j,k,i);
	//				printf("(%d, %d)\n", j,k);
					cnt++;
				}
				
			}
		}
		if(cntMax<cnt)
			cntMax=cnt;
	//	printf("%d\n", cnt);
	}
	printf("%d", cntMax);

	return 0;
}
