#include<stdio.h>
#include<queue>
using namespace std;
int map[101][101][101];
bool visit[101][101][101];
int M,N,H;
struct Idx{
	int a;
	int b;
	int c;
};
queue<struct Idx> q;
int dir[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int cnt=0;
void bfs()
{
	while(!q.empty())
	{
		int size = q.size();
		cnt++;
		for(int i=0;i<size;i++)
		{
			int a = q.front().a;
			int b = q.front().b;
			int c = q.front().c;
			q.pop();
			for(int j=0;j<6;j++)
			{
				int nx = a+dir[j][0];
				int ny = b+dir[j][1];
				int nz = c+dir[j][2];
				if(nx>0&&nx<=H&&ny>0&&ny<=N&&nz>0&&nz<=M&&map[nx][ny][nz]==0)
				{
					if(visit[nx][ny][nz]==0)
					{
						visit[nx][ny][nz]=1;
						struct Idx idx = {nx,ny,nz};
						q.push(idx);
					}
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d %d", &M,&N,&H);
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=M;k++)
			{
				scanf("%d", &map[i][j][k]);
				if(map[i][j][k]==1){
					struct Idx idx = {i,j,k};
					q.push(idx);
					visit[i][j][k]=1;
					idx = q.front();
	//				printf("%d %d %d\n", idx.a, idx.b, idx.c);
				}
				if(map[i][j][k]==-1)
					visit[i][j][k]=1;
			}
		}
	}
	bfs();
//	printf("\n");
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=M;k++)
			{
			//	printf("%d ", visit[i][j][k]);
				if(visit[i][j][k]==0){
					printf("-1");
					return 0;
				}
			}
	//		printf("\n");
		}
	//	printf("\n");
	}
	printf("%d", cnt-1);
	return 0;
}
