#include<stdio.h>
#include<string.h>
int map[101][101];
int N;
bool visit[101];
bool res[101][101];
void dfs(int idx)
{
	for(int i=1;i<=N;i++)
	{
		if(map[idx][i]==1&&visit[i]==0)
		{
			visit[i]=1;
			dfs(i);
		}
	}
}
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for(int i=1;i<=N;i++)
	{
		memset(visit,0,sizeof(visit));
		dfs(i);
		for(int j=1;j<=N;j++)
			res[i][j]=visit[j];
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			printf("%d ",res[i][j]);
		printf("\n");
	}

	return 0;
}
