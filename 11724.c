#include<stdio.h>
int N,M;
int map[1001][1001];
int visit[1001];
void dfs(int idx)
{
	visit[idx]=1;
	for(int i=1;i<=N;i++)
	{
		if(map[idx][i]==1&&visit[i]==0)
		{
			dfs(i);
		}
	}
}
int main()
{
	scanf("%d %d", &N,&M);
	int a,b;
	for(int i=0;i<M;i++)
	{
		scanf("%d %d", &a,&b);
		map[a][b]=1;
		map[b][a]=1;
	}
	int cnt=0;
	for(int i=1;i<=N;i++)
	{
		if(visit[i]==0){
			dfs(i);
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
