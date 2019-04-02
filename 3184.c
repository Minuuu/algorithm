#include<stdio.h>
#include<queue>
using namespace std;
int R,C;
char map[251][251];
bool visit[251][251];
queue<pair<int,int>> q;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int O,V;
void bfs(int a, int b)
{
	int scnt=0;
	int wcnt=0;
	visit[a][b]=1;
	if(map[a][b]=='v')
		wcnt++;
	if(map[a][b]=='o')
		scnt++;
	q.push(pair<int,int>(a,b));
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx = x+dir[i][0];
			int ny = y+dir[i][1];
			if(nx>0&&nx<=R&&ny>0&&ny<=C&&visit[nx][ny]==0&&map[nx][ny]!='#')
			{
				if(map[nx][ny]=='v')
					wcnt++;
				else if(map[nx][ny]=='o')
					scnt++;
				visit[nx][ny]=1;
				q.push(pair<int,int>(nx,ny));
			}
		}
	}
//	printf("v: %d, o: %d\n", wcnt,scnt);
	if(wcnt<scnt)
		O+=scnt;
	else
		V+=wcnt;
}
int main()
{
	scanf("%d %d", &R, &C);
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++)
			scanf(" %1c", &map[i][j]);
	}
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++)
		{
			if(visit[i][j]==0&&map[i][j]!='#'){
		//		printf("%d, %d\n", i,j);
				bfs(i,j);
			}
		}
	}
	printf("%d %d", O,V);
	return 0;
}
