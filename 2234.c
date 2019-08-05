#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int N,M;
int map[51][51];
int visit[51][51];
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
void print(int arr[51][51])
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
			printf("%d ", visit[i][j]);
		printf("\n");
	}
}
int bfs(int x, int y, int val)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	visit[x][y]=val;
	int cnt=1;
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			if((map[cx][cy]&1<<i)==0){
				//printf("i: %d\n", i);
				int nx = cx+dir[i][0];
				int ny = cy+dir[i][1];
				if(nx>=1&&nx<=N&&ny>=1&&ny<=M)
				{
					if(visit[nx][ny]==0)
					{
						visit[nx][ny]=val;
						cnt++;
						q.push({nx,ny});

					}
				}
			}
		}
	}
	return cnt;
}
int main()
{
	scanf("%d %d", &M, &N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
			scanf("%d", &map[i][j]);
	}
	int cnt=0;
	int ans= -1;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(visit[i][j]==0)
			{
				cnt++;
				int ret = bfs(i,j,cnt);
			//	printf("ret: %d\n", ret);
				ans = max(ret,ans);
				//print(visit);
				//return 0;
			}
		}
	}
	//print(visit);
	printf("%d\n%d\n", cnt,ans);
	int aans=-1;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			for(int k=0;k<4;k++)
			{
				int idx = 1<<k;
				map[i][j]-=idx;
				memset(visit,0,sizeof(visit));
	//			if(visit[i][j]==0)
				aans = max(aans,bfs(i,j,1));
				map[i][j]+=idx;
			}
		}
	}
	printf("%d\n", aans);
	return 0;
}
