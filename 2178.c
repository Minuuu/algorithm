#include<stdio.h>
#include<queue>
using namespace std;
queue<pair<int,int>> q;
int N,M;
int map[101][101];
int visit[101][101];
int dirx[4]={0,1,-1,0};
int diry[4]={1,0,0,-1};
void bfs()
{
	int i,j;
	q.push(pair<int,int>(1,1));
	visit[1][1]=1;
	while(!q.empty())
	{
		i=q.front().first;
		j=q.front().second;
		q.pop();
		if(i==N&&j==M){
			return;
		}
		for(int k=0;k<4;k++)
		{
			int nx = i+dirx[k];
			int ny = j+diry[k];

			if(!visit[nx][ny]&&map[nx][ny]==1&&nx>0&&nx<=100&&ny>0&&ny<=100)
			{
				q.push(pair<int,int>(nx,ny));
				visit[nx][ny]=visit[i][j]+1;
			}
		}

	}	
}
int main()
{
	scanf("%d %d", &N,&M);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			scanf("%1d", &map[i][j]);
	bfs();
	printf("%d", visit[N][M]);
	return 0;
}
