#include<stdio.h>
#include<queue>
using namespace std;
int R,C;
int map[51][51];
bool visit[51][51];
bool wvisit[51][51];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct Node{
	int a,b,cnt;
};
queue<struct Node> q, wq;
int bfs()
{
	while(!q.empty())
	{
		int size = wq.size();
		//printf("##wq size: %d\n", size);
		for(int i=0;i<size;i++)
		{
			int x = wq.front().a;
			int y = wq.front().b;
			int cnt = wq.front().cnt;
			wq.pop();
			for(int j=0;j<4;j++)
			{
				int nx = x+dir[j][0];
				int ny = y+dir[j][1];
				if(nx<=0||nx>R||ny<=0||ny>C)
					continue;
				if(map[nx][ny]=='X'||map[nx][ny]=='D')
					continue;
				else if(wvisit[nx][ny]==0){
					map[nx][ny]='*';
					wvisit[nx][ny]=1;
					wq.push({nx,ny,cnt+1});
				}
			}
		}

		size = q.size();
		//printf("##q size: %d\n", size);
		for(int i=0;i<size;i++)
		{
			int x = q.front().a;
			int y = q.front().b;
			int cnt = q.front().cnt;
			if(map[x][y]=='D')
				return cnt;
			q.pop();
			for(int j=0;j<4;j++)
			{
				int nx = x+dir[j][0];
				int ny = y+dir[j][1];
				if(nx<=0||nx>R||ny<=0||ny>C)
					continue;
				if(map[nx][ny]=='X'||map[nx][ny]=='*')
					continue;
				else if(visit[nx][ny]==0){
					visit[nx][ny]=1;
					q.push({nx,ny,cnt+1});
				}
					
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d %d", &R,&C);
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++)
		{
			scanf(" %c", &map[i][j]);
			if(map[i][j]=='S'){
				q.push({i,j,0});
				visit[i][j]=1;
			}
			if(map[i][j]=='*'){
				wvisit[i][j]=1;
				wq.push({i,j,0});
			}
		}
	}
	int res = bfs();
	if(res==-1)
		printf("KAKTUS");
	else
		printf("%d", res);
	return 0;
}
