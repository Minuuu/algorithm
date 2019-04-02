#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
int T;
int L;
int map[300][300];
int visit[300][300];
int dir[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int sx,sy,ex,ey;
void bfs()
{
	queue<pair<int,int>> q;
	q.push(pair<int,int>(sx,sy));
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
//		printf("%d %d\n", x,y);
		for(int i=0;i<8;i++)
		{
			int nx = x+dir[i][0];
			int ny = y+dir[i][1];
			if(nx>=0&&nx<L&&ny>=0&&ny<L&&map[nx][ny]==0){
				map[nx][ny]=map[x][y]+1;
				if(nx==ex&&ny==ey)
					return;
				q.push(make_pair(nx,ny));
			}
		}
	}

}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &L);
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &ex, &ey);
		map[sx][sy]=1;
		bfs();
		printf("%d\n", map[ex][ey]-1);
		memset(map,0,sizeof(map));
	}
	return 0;
}
