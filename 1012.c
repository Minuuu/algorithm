#include<stdio.h>
#include<string.h>
int M,N,K,T;
int map[50][50];
int visit[50][50];
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
void dfs(int i, int j)
{
	visit[i][j]=1;
	for(int k=0;k<4;k++)
	{
		int nx = i+dir[k][0];
		int ny = j+dir[k][1];
		if(nx>=0&&nx<50&&ny>=0&&ny<50&&map[nx][ny]==1&&visit[nx][ny]==0)
		{
//			visit[nx][ny]=1;
			dfs(nx,ny);
		}
	}
}
int main()
{
	scanf("%d", &T);
	int a,b;
	for(int i=0;i<T;i++)
	{
		int cnt=0;
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		scanf("%d %d %d", &M, &N, &K);
		for(int j=0;j<K;j++)
		{
			scanf("%d %d", &a,&b);
			map[a][b]=1;
		}
		for(int j=0;j<M;j++)
		{
			for(int k=0;k<N;k++)
			{
				if(map[j][k]==1&&visit[j][k]==0)
				{
					dfs(j,k);
//					visit[j][k]=1;
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
