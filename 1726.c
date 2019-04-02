#include<stdio.h>
#include<queue>
using namespace std;
struct Node{
	int x,y,p,cnt;
};
queue<struct Node> q;
int dir[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
int M,N;
int map[101][101];
int visit[101][101][5];
	int sx,sy, sp;
	int ex,ey, ep;
void bfs()
{
	visit[sx][sy][sp]=1;
	q.push({sx,sy,sp,0});
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int p = q.front().p;
		int cnt = q.front().cnt;
		q.pop();
		int nx=x;
		int ny=y;
		//printf("%d %d %d\n", x,y,p);
		if(x==ex&&y==ey&&p==ep){
			printf("%d", cnt);
			return ;
		}
			
		for(int i=1;i<=3;i++)
		{
			nx = nx+dir[p][0];
			ny = ny+dir[p][1];
			if(map[nx][ny]!=0||nx<=0||nx>M||ny<=0||ny>N){
				break;
			}
			else if(visit[nx][ny][p]==0)
			{
				visit[nx][ny][p]=1;
		//		printf("0## %d %d %d\n", nx,ny,p);
				q.push({nx,ny,p,cnt+1});
			}
		}
		if(p==1||p==2){
			p=3;	
			if(visit[x][y][p]==0){
				visit[x][y][p]=1;
		//		printf("1## %d %d %d\n", nx,ny,p);
				q.push({x,y,p,cnt+1});
			}
			p=4;
			if(visit[x][y][p]==0){
				visit[x][y][p]=1;
		//		printf("2## %d %d %d\n", nx,ny,p);
				q.push({x,y,p,cnt+1});
			}
			continue;
		}
		else if(p==3||p==4)
		{
			p=1;
			if(visit[x][y][p]==0){
				visit[x][y][p]=1;
		//		printf("3## %d %d %d\n", nx,ny,p);
				q.push({x,y,p,cnt+1});
			}
			p=2;
			if(visit[x][y][p]==0){
				visit[x][y][p]=1;
		//		printf("4## %d %d %d\n", nx,ny,p);
				q.push({x,y,p,cnt+1});
			}
		}

	}
}
int main()
{
	scanf("%d %d", &M, &N);
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d %d %d", &sx, &sy, &sp);
	scanf("%d %d %d", &ex, &ey, &ep);

	bfs();
	return 0;
}
