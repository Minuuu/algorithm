#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int N;
int map[26][26];
bool visit[26][26];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
vector<int> v;
queue<pair<int,int>> q;
int bfs(int i,int j)
{
	int cnt=1;
	int x,y;
	q.push(pair<int,int>(i,j));
	visit[i][j]=1;
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		q.pop();
		//printf("%d %d\n", x,y);

		for(int k=0;k<4;k++)
		{
			int nx = x+dir[k][0];
			int ny = y+dir[k][1];
			if(nx>=1&&nx<=25&&ny>=1&&ny<=25&&map[nx][ny]&&!visit[nx][ny])
			{
	//			printf("%d %d\n", nx,ny);
				visit[nx][ny]=1;
				q.push(pair<int,int>(nx,ny));
				cnt++;
			}

		}
	}
	return cnt;
}
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			scanf("%1d", &map[i][j]);
	int cnt=0;
	int res;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(map[i][j]==1&&visit[i][j]==0){
				res=bfs(i,j);
				v.push_back(res);
				cnt++;
			//	return -1;
			}
		}
	}
	sort(v.begin(),v.end());
	printf("%d\n",cnt);
	for(int i=0;i<v.size();i++)
		printf("%d\n",v[i]);
	return 0;
}
