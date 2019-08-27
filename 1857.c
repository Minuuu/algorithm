#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
int dir[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
long long dp[31][31];
long long cnt[31][31];
int map[31][31];
vector<pair<int,int>> v[31][31];
int sx,sy,ex,ey;
int n,m;
void bfs(int x, int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	bool visit[31][31]={0,};
	visit[x][y]=true;
	if(1)
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy =q.front().second;
	//	printf("## %d %d\n", cx,cy);
		q.pop();
		if(map[cx][cy]!=1&&!(x==cx&&y==cy))
		{
			v[x][y].push_back({cx,cy});
			continue;
		}
		for(int i=0;i<8;i++)
		{
			int nx = cx+dir[i][0];
			int ny = cy+dir[i][1];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&visit[nx][ny]==false)
			{
				if(map[nx][ny]!=2)
				{
					q.push({nx,ny});
					visit[nx][ny]=true;
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j]==3)
			{
				sx=i;
				sy=j;
			}
			if(map[i][j]==4)
			{
				ex=i;
				ey=j;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]!=2)
				bfs(i,j);
		}
	}

	bool visit[31][31]={0,};
	memset(dp,-1,sizeof(dp));
	cnt[sx][sy]=1;
	dp[sx][sy]=0;
	queue<pair<int,int>> q;
	q.push({sx,sy});
	/*
	printf("%d %d\n" ,sx,sy);
	for(int i=0;i<v[sx][sy].size();i++)
		printf("%d %d\n", v[sx][sy][i].first, v[sx][sy][i].second);
	*/
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
//		printf("%d\n", v[cx][cy].size());
		for(int i=0;i<v[cx][cy].size();i++)
		{
			int nx = v[cx][cy][i].first;
			int ny = v[cx][cy][i].second;
			if(dp[nx][ny]!=-1)
			{
				if(dp[nx][ny]==dp[cx][cy]+1){
					cnt[nx][ny]+=cnt[cx][cy];
				}
				continue;
			}

			cnt[nx][ny] = cnt[cx][cy];
			dp[nx][ny] = dp[cx][cy]+1;
			q.push({nx,ny});

		}
	}
	if(cnt[ex][ey]==0){
		printf("-1\n");
	}
	else{
		printf("%lld\n", dp[ex][ey]-1);
		printf("%lld\n", cnt[ex][ey]);
	}

	return 0;
}
