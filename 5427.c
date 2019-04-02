#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int T;
char map[1002][1002];
bool visit[1002][1002];
int W,H;
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int cnt=0;
int bfs(queue<pair<int,int>> q, queue<pair<int,int>> fq)
{
	while(!q.empty())
	{
		cnt++;
		int size = fq.size();
		for(int i=0;i<size;i++)
		{
			int x = fq.front().first;
			int y = fq.front().second;
			fq.pop();
			for(int j=0;j<4;j++)
			{
				int nx = x+dir[j][0];
				int ny = y+dir[j][1];
				if(nx>0&&ny>0&&nx<=H&&ny<=W&&map[nx][ny]=='.'){
					map[nx][ny]='*';
					fq.push(make_pair(nx,ny));
				}
			}
		}

		size = q.size();
		for(int i=0;i<size;i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int j=0;j<4;j++)
			{
				int nx = x+ dir[j][0];
				int ny = y+ dir[j][1];
				if(nx<=0||ny<=0||nx>H||ny>W){
					return 1;
				}
				if(map[nx][ny]=='.'&&visit[nx][ny]==0){
					visit[nx][ny]=1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	/*
	   size = fq.size();
		   for(int i=0;i<size;i++)
		   {
		   int x = fq.front().first;
		   int y = fq.front().second;
		   fq.pop();
		   for(int j=0;j<4;j++)
		   {
		   int nx = x+dir[j][0];
		   int ny = y+dir[j][1];
		   if(nx>0&&ny>0&&nx<=H&&ny<=W&&map[nx][ny]=='.'){
		   map[nx][ny]='*';
		   fq.push(make_pair(nx,ny));
		   }
		   }
		   }
		   }
		   */
		/*
		   for(int i=1;i<=H;i++)
		   {
		   for(int j=1;j<=W;j++)
		   printf("%c ", map[i][j]);
		   printf("\n");
		   }
		   */
	return -1;

}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &W, &H);
		queue<pair<int,int>> q,fq;

		
		for(int i=1;i<=H;i++)
		{
			for(int j=1;j<=W;j++)
			{
				scanf(" %c", &map[i][j]);
				if(map[i][j]=='@'){
					q.push(make_pair(i,j));
				}
				if(map[i][j]=='*'){
					fq.push(make_pair(i,j));
				}
			}
		}
		int res = bfs(q,fq);
		if(res==-1)
			printf("IMPOSSIBLE\n");
		else if(res==1)
			printf("%d\n",cnt);
		cnt=0;
		memset(visit,0,sizeof(visit));
	}
	return 0;
}
