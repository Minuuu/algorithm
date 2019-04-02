#include<stdio.h>
int R,C;
char map[21][21];
bool visit[26];
int ans=0;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int a, int b,int cnt)
{
	if(ans<cnt)
		ans=cnt;
	for(int i=0;i<4;i++)
	{
		int nx = a+dir[i][0];
		int ny = b+dir[i][1];
		if(nx>0&&nx<=R&&ny>0&&ny<=C&&visit[map[nx][ny]-'A']==0){
			visit[map[nx][ny]-'A']=1;
			//printf("%c\n", map[nx][ny]);
			dfs(nx,ny,cnt+1);
			visit[map[nx][ny]-'A']=0;
		}

	}
}
int main()
{
	scanf("%d %d", &R, &C);
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			scanf(" %c", &map[i][j]);
	visit[map[1][1]-'A']=1;
	dfs(1,1,1);
	printf("%d", ans);
	return 0;
}
