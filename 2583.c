#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int M,N,K;
int map[100][100];
bool visit[100][100];
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int zero=0;
void dfs(int a, int b)
{
	visit[a][b]=1;
	zero++;
	for(int i=0;i<4;i++)
	{
		int nx = a+dir[i][0];
		int ny = b+ dir[i][1];
		if(nx>=0&&ny>=0&&ny<N&&nx<M&&!visit[nx][ny]&&!map[nx][ny])
			dfs(nx,ny);
	}
}
int main()
{
	int lx,ly, rx,ry;
	scanf("%d %d %d", &M, &N, &K);
	for(int i=0;i<K;i++)
	{
		scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
		for(int j=ly;j<ry;j++)
		{
			for(int k=lx;k<rx;k++)
				map[j][k]=1;
		}
	}
	/*
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	*/
	int cnt=0;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(map[i][j]==0&&visit[i][j]==0){
				zero=0;
				dfs(i,j);
				cnt++;
				v.push_back(zero);
			}
		}
	}
	/*
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++)
			printf("%d ", visit[i][j]);
		printf("\n");
	}
	*/
	printf("%d\n", cnt);
	sort(v.begin(),v.end());
	for(int i=0;i<cnt;i++)
		printf("%d ", v[i]);
	return 0;
}
