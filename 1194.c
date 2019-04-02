#include<stdio.h>
#include<queue>
using namespace std;
int N,M;
char map[51][51];
int visit[51][51][64];
struct Node{
	int x,y,key;
};
queue<struct Node> q;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int cnt=0;
int bfs()
{
	while(!q.empty())
	{
		int size = q.size();
		for(int i=0;i<size;i++){
			int x = q.front().x;
			int y = q.front().y;
			int key = q.front().key;
		//	printf("%d %d %d %c\n", x,y,key, map[x][y]);
			q.pop();
			if(map[x][y]=='1')
			{
		//		printf("ok\n");
				return visit[x][y][key]-1;
			}
			for(int i=0;i<4;i++)
			{
				int nx = x+dir[i][0];
				int ny = y+dir[i][1];
				if(nx<=0 || ny<=0 || nx>N || ny>M || map[nx][ny]=='#' || visit[nx][ny][key]!=0)
					continue;

				if(map[nx][ny]>='a'&&map[nx][ny]<='f')
				{
					int k = key|(1<< map[nx][ny]-'a');
					if(visit[nx][ny][k]==0){
						visit[nx][ny][k]=visit[x][y][key]+1;
						visit[nx][ny][key]=visit[x][y][key]+1;
						q.push({nx,ny,k});
					}
				}
				else if(map[nx][ny]>='A'&&map[nx][ny]<='F')
				{
					int k = key&(1<<map[nx][ny]-'A');
					if(k!=0)
					{
						visit[nx][ny][key]=visit[x][y][key]+1;
						q.push({nx,ny,key});
					}
				}
				else if(visit[nx][ny][key]==0){
					visit[nx][ny][key] = visit[x][y][key]+1;
					q.push({nx,ny,key});

				}
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d %d", &N, &M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf(" %c", &map[i][j]);
			if(map[i][j]=='0'){
				q.push({i,j,0});
				visit[i][j][0]=1;
			}
		}
	}
	int ans=bfs();
	printf("%d", ans);
	return 0;
}
