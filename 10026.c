#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
char map[101][101];
bool visit[101][101];
int N;
queue<pair<int,int>> q;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void bfs(int a, int b, char c)
{
	q.push(pair<int,int>(a,b));
	visit[a][b]=1;
	while(!q.empty())
	{
		int x= q.front().first;
		int y= q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx = x+dir[i][0];
			int ny = y+dir[i][1];
			if(nx>0&&nx<=N&&ny>0&&ny<=N&&visit[nx][ny]==0&&map[nx][ny]==c)
			{
				q.push(pair<int,int>(nx,ny));
				visit[nx][ny]=1;
			}
		}
	}
}
int main()
{
	int cnt=0;
	int r, g;
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++){
			scanf(" %c",&map[i][j]);
		}
	}
	/*
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			printf("%d", &map[i][j]);
		}
		printf("\n");
	}
	*/
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(map[i][j]=='R'&&visit[i][j]==0){
				bfs(i,j,'R');
				cnt++;
			}
			else if(map[i][j]=='G'&&visit[i][j]==0){
				cnt++;
				bfs(i,j,'G');
			}
			else if(map[i][j]=='B'&&visit[i][j]==0){
				bfs(i,j,'B');
				cnt++;
			}
		}
	}
	printf("%d ",cnt);
	cnt=0;
	memset(visit,0,sizeof(visit));
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(map[i][j]=='R'||map[i][j]=='G'){
				map[i][j]='A';
			}
		}
	}
	/*
	printf("\n");
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			printf("%d", map[i][j]);
		printf("\n");
	}
	*/
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(map[i][j]=='A'&&visit[i][j]==0){
				bfs(i,j,'A');
				cnt++;
			}
			else if(map[i][j]=='B'&&visit[i][j]==0){
				bfs(i,j,'B');
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
