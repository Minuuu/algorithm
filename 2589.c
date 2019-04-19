#include<iostream>
#include<climits>
#include<cstring>
#include<queue>
using namespace std;
int N,M;
char map[51][51];
int visit[51][51];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
typedef struct{
	int x,y,cnt;
} Node;
int bfs(int x, int y)
{
	queue<Node> q;
	visit[x][y]=1;
	q.push({x,y,0});
	int ret=-1;
	while(!q.empty())
	{
		int size = q.size();
		for(int i=0;i<q.size();i++)
		{
			int qx = q.front().x;
			int qy = q.front().y;
			int cnt = q.front().cnt;
			q.pop();
			ret=max(cnt,ret);
			for(int j=0;j<4;j++)
			{
				int nx = qx+dir[j][0];
				int ny = qy+dir[j][1];
				if(nx>0&&nx<=N&&ny>0&&ny<=M&&visit[nx][ny]==0)
				{
					if(map[nx][ny]=='L')
					{
						visit[nx][ny]=cnt+1;
						q.push({nx,ny,cnt+1});
					}
				}
			}

		}
	}
	//cout<<ret<<endl;
	return ret;
}

int main()
{
	cin>>N>>M;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
			cin>>map[i][j];
	}
	int ans=-1;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(map[i][j]=='L')
			{
				memset(visit,0,sizeof(visit));
				ans=max(ans,bfs(i,j));
			}
		}
	}
	cout<<ans;
	return 0;
}
