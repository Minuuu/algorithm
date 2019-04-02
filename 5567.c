#include<stdio.h>
#include<queue>
int N,M;
int map[501][501];
int visit[501];
int cnt=0;
using namespace std;
queue<int> q;
void dfs(int idx, int lvl)
{
	if(lvl>=2)
		return ;
	for(int i=1;i<=500;i++)
	{
		if(map[idx][i]==1)
		{
			if(visit[i]==0)
			{
				cnt++;
				visit[i]=1;
//				printf("## %d %d %d\n", idx,i, visit[i]);
				dfs(i,lvl+1);
			}
		}
	}
}
int main()
{
	int a,b,i;
	scanf("%d", &N);
	scanf("%d", &M);
	for(int i=1;i<=M;i++)
	{
		scanf("%d %d", &a,&b);
		map[a][b]=1;
		map[b][a]=1;
	}
	for(i=1;i<=N;i++)
	{
		if(map[1][i]==1)
		{
			cnt++;
			visit[i]=1;
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for(i=2;i<=N;i++){
			if(map[tmp][i]==1)
			{
				if(visit[i]==0){
					visit[i]=1;
					cnt++;
				}
			}
		}
	}
	printf("%d", cnt);
	


	return 0;
}

