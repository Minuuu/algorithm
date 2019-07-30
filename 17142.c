#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
int map[51][51];
typedef struct{
	int x, y;
} Node;
Node n[10];
int visit[10];
int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
int N,M;
int res=INT_MAX;
void print(int arr[51][51])
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

}
int chk[51][51];
void bfs(queue<pair<int, int> > q)
{
	//printf("%d\n", q.size());
	while(!q.empty())
	{
		int size = q.size();
		for(int i=0;i<size;i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int j=0;j<4;j++)
			{
				int nx = x+dir[j][0];
				int ny = y+dir[j][1];
				if(nx>=1&&nx<=N&&ny>=1&&ny<=N&&map[nx][ny]!=1&&chk[nx][ny]==-1)
				{
					chk[nx][ny]=chk[x][y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	//print(chk);
	int mt=0;
	bool flag= false;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(map[i][j]==0)
			{
				if(chk[i][j]==-1){
					flag=true;
					break;
				}
				else
					mt = max(mt,chk[i][j]);
			}
		}
	}
	//printf("mt: %d\n", mt);
	if(!flag)
		res = min(res,mt);
	return ;
}
void solve(int idx, int cnt, int size)
{
	if(cnt==M)
	{
		queue<pair<int, int> > q;
		memset(chk,-1,sizeof(chk));
		for(int i=0;i<idx;i++)
		{	
			if(visit[i]==1)
			{	
				q.push(make_pair(n[i].x,n[i].y));
				chk[n[i].x][n[i].y]=0;
	//			printf("%d %d ", n[i].x,n[i].y);
			}
		}
	//	printf("\n");
		bfs(q);
		return ;
	}
	if(idx>=size)
		return ;
	visit[idx]=1;
	solve(idx+1,cnt+1,size);
	visit[idx]=0;
	solve(idx+1,cnt,size);
}
int main()
{
	scanf("%d %d", &N, &M);
	int cnt=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j]==2){
				n[cnt].x=i;
				n[cnt].y=j;
				cnt++;
			}
		}
	}
	solve(0,0,cnt);
	if(res==INT_MAX)
		res=-1;
	printf("%d\n", res);
	return 0;
}
