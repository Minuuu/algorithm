#include<stdio.h>
#include<queue>
#include<vector>
#include<functional>
#define INF 987654321
using namespace std;
vector<pair<int,int>> v[300001];
int weight[20001];
void dij(int K)
{
	priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,K});
	while(!pq.empty())
	{
		int w = pq.top().first;
		int vtx = pq.top().second;
		pq.pop();
		for(int i=0;i<v[vtx].size();i++)
		{
			int nv = v[vtx][i].second;
			int nw = v[vtx][i].first;
			if(weight[nv]>w+nw)
			{
				weight[nv] = w+nw;
				pq.push({weight[nv],nv});
			}
		}
	}
}
int main()
{
	int V,E;
	scanf("%d %d", &V, &E);
	int K;
	scanf("%d", &K);
	for(int i=1;i<=E;i++)
	{
		int a,b,w;
		scanf("%d %d %d", &a,&b,&w);
		v[a].push_back({w,b});
	}
	for(int i=1;i<=V;i++)
	{
		weight[i] = INF;
	}
	dij(K);
	weight[K] = 0;
	for(int i=1;i<=V;i++)
	{
		if(weight[i]==INF)
			printf("INF\n");
		else
			printf("%d\n", weight[i]);
	}
	return 0;
}
