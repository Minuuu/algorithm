#include<stdio.h>
#include<string.h>
int T;
int C;
int map[1001];
int visit[1001];
int cnt=0;
void dfs(int idx, int start)
{
	if(idx==start){
		cnt++;
		return;
	}
	visit[idx]=1;
	dfs(map[idx],start);
}
int main()
{
	scanf("%d", &T);
	for(int i=0;i<T;i++)
	{
		memset(visit,0,sizeof(visit));
		memset(map,0,sizeof(map));
		cnt=0;
				
		scanf("%d", &C);
		for(int j=1;j<=C;j++)
		{
			scanf("%d", &map[j]);
		}
		for(int j=1;j<=C;j++)
		{
			if(visit[j]==0){
				visit[j]=1;
				dfs(map[j],j);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
