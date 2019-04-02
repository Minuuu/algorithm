#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
int T,N,M;
int visit[21][21];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int map[21][21];
int save[22];
int cal(int k)
{
	return (k*k)+(k-1)*(k-1);
}
void bfs(int x, int y)
{
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	visit[x][y]=1;
	if(map[x][y]==1)
		save[1]=1;
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if(visit[cx][cy]>N+1){
			return ;
		}
		for(int i=0;i<4;i++)
		{
			int nx = cx+dir[i][0];
			int ny = cy+dir[i][1];
			if(nx<=0||ny<=0||nx>N||ny>N)
				continue;
			if(map[nx][ny]==1&&visit[nx][ny]==0)
				save[visit[cx][cy]+1]+=1;
			if(visit[nx][ny]==0){
				visit[nx][ny]=visit[cx][cy]+1;
				q.push(make_pair(nx,ny));
			}
		}
	}
}
int getResult()
{
	int sum=0;
	int num=-1;
	for(int i=1;i<=N+1;i++)
	{
		int k = cal(i);
		sum += save[i];
		if(sum*M-k>=0){
			num= sum;
		}
	}
	return num;
}
int main()
{
	scanf("%d", &T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d %d", &N, &M);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				scanf("%d", &map[i][j]);
		int res=-1;
		int max=-1;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++){
				memset(visit,0,sizeof(visit));
				memset(save,0,sizeof(save));
				bfs(i,j);
				res = getResult();
				if(max<res){
					max=res;
				}
			}
		}
		printf("#%d %d\n", t,max);
	}
}
