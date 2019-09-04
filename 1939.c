#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> v[10001];
int n,m;
int visit[10001];
int solve(int s, int e)
{
	pq.push({INT_MAX,s});
	while(!pq.empty())
	{
		int num = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(num==e)
		{
			return cost;
		}
		if(visit[num])
			continue;
		visit[num] = 1;
		for(int i=0;i<v[num].size();i++)
		{
			int nn = v[num][i].first;
			int nc = min(v[num][i].second,cost);
			if(!visit[nn])
			{
				pq.push({nc,nn});
			}
		}
	}
	
	return 0;
}
int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	int s,e;
	scanf("%d", &s);
	scanf("%d", &e);
	printf("%d\n", solve(s,e));
	return 0;
}
