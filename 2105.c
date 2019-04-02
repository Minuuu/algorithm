#include<stdio.h>
#include<string.h>
int T, N;
int map[21][21];
int desert[101];
int dir[4][2]={{1,1},{1,-1},{-1,-1},{-1,1}};
int sx,sy;
int ans=-1;
void solve(int x, int y, int d, int cnt)
{
	if(x==sx&&y==sy){
		if(ans<cnt){
			ans=cnt;
		}
	//	printf("ans: %d\n", ans);
	}
//	desert[map[x][y]]=1;
	for(int i=d;i<=d+1;i++){
		if(i==4)
			break;
		int nx = x+dir[i][0];
		int ny = y+dir[i][1];
//		printf("(%d, %d) %d %d\n", nx,ny,map[nx][ny],desert[map[nx][ny]]);
		if(nx>=1&&nx<=N&&ny>=1&&ny<=N&&desert[map[nx][ny]]==0){
//			printf("%d %d %d %d\n", nx,ny, map[nx][ny], i);
	//		printf("map: %d\n", map[nx][ny]);
			desert[map[nx][ny]]=1;
			solve(nx,ny,i,cnt+1);
			desert[map[nx][ny]]=0;
		}
	}
}
int main()
{
	scanf("%d", &T);
	for(int i=1;i<=T;i++)
	{
		memset(map,0,sizeof(map));
		ans=-1;
		scanf("%d", &N);
		for(int j=1;j<=N;j++)
			for(int k=1;k<=N;k++)
				scanf("%d", &map[j][k]);
		for(int j=1;j<=N-2;j++)
			for(int k=2;k<=N-1;k++){
				if(map[j][k]!=map[j+1][k+1]&&map[j+1][k-1]!=map[j][k]){
					sx=j+1;
					sy=k-1;
					desert[map[j][k]]=1;
					desert[map[j+1][k+1]]=1;
	//				printf("start %d %d\n", j,k);
					solve(j+1,k+1,0,2);
					desert[map[j][k]]=0;
					desert[map[j+1][k+1]]=0;
				}
			}
		printf("#%d %d\n", i, ans);
	}
	return 0;
}
