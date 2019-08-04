#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int N,M,K;
int map[1001][1001];
int visit[1001][1001][10];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int ans=987654321;
typedef struct node{
	int x,y,cnt,state;
} Node;
void solve(int x,int y)
{
	queue<Node> q;
	q.push({x,y,1,0});
	while(!q.empty())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		int cnt = q.front().cnt;
		int state = q.front().state;
		q.pop();
		if(cx==N&&cy==M)
		{
			ans = min(cnt,ans);
		}
		for(int i=0;i<4;i++)
		{
			int nx = cx+dir[i][0];
			int ny = cy+dir[i][1];
			if(nx>=1&&nx<=N&&ny>=1&&ny<=M)
			{
				if(visit[nx][ny][state]==0)
				{
					if(map[nx][ny]==0)
					{
						visit[nx][ny][state]=1;
						q.push({nx,ny,cnt+1,state});
					}
					else
					{
						if(state<K)
						{
							visit[nx][ny][state]=1;
							q.push({nx,ny,cnt+1,state+1});
						}
					}
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
			scanf("%1d", &map[i][j]);
	}
	visit[1][1][0]=1;
	solve(1,1);
	if(ans==987654321)
		ans=-1;
	printf("%d\n", ans);
	return 0;
}
