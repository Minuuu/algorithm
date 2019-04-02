#include<stdio.h>
int N, M;
int map[50][50];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int back[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
int ans=1;
int changeDir(int d)
{
	switch(d)
	{
		case 0:
			return 3;
		case 1:
			return 0;
		case 2:
			return 1;
		case 3:
			return 2;
	}
}
void solve(int x, int y, int d)
{
	map[x][y]=2;
	for(int i=0;i<4;i++){
		d = changeDir(d);
		int nx = x+dir[d][0];
		int ny = y+dir[d][1];
		if(nx>=0&&nx<N&&ny>=0&&ny<M){
			if(map[nx][ny]==0){
				ans++;
				solve(nx,ny,d);
				return ;
			}
		}
	}

	int nx= x+back[d][0];
	int ny = y+back[d][1];
	if(nx>=0&&nx<N&&ny>=0&&ny<M&&map[nx][ny]!=1)	
		solve(nx,ny,d);
}
int main()
{
	scanf("%d %d", &N, &M);
	int x,y,d;
	scanf("%d %d %d", &x, &y, &d);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			scanf("%d", &map[i][j]);
	}
	map[x][y]=2;
	solve(x,y,d);
	printf("%d\n", ans);
	return 0;
}
