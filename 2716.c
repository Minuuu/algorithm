#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
int visit1[100];
int visit[100];
int N,M;
vector<int> high[100];
vector<int> low[100];
int dfs1(int idx)
{
	int cnt = 1;
	visit1[idx] = 1;
	for(int i=0;i<high[idx].size();i++)
	{
		if(!visit1[high[idx][i]])
		{
			cnt+=dfs1(high[idx][i]);
		}
	}
	return cnt;
}
int dfs(int idx)
{
	int cnt = 1;
	visit[idx] = 1;
	for(int i=0;i<low[idx].size();i++)
	{
		if(!visit[low[idx][i]])
		{
			cnt+=dfs(low[idx][i]);
		}
	}
	return cnt;
}
int main()
{
	scanf("%d %d", &N, &M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		high[a].push_back(b);
		low[b].push_back(a);
	}
	int ans = 0;
	for(int i=1;i<=N;i++)
	{
		memset(visit1,0,sizeof(visit1));
		memset(visit,0,sizeof(visit));
		int ret = dfs(i);
		int ret1 = dfs1(i);
		if(ret>(N+1)/2||ret1>(N+1)/2)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
