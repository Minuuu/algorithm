#include<stdio.h>
#include<queue>
#include<vector>
#include<functional>
#include<string.h>
#define INF 987654321
using namespace std;
vector<pair<int,int>> v[501],v1[501];
int weight[501];
int path[501][501];
int n,m;
void dij(int start)
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,start});
	for(int i=0;i<n;i++)
		weight[i] = INF;
	weight[start] = 0;
	while(!pq.empty())
	{
		int cw = pq.top().first;
		int cv = pq.top().second;
		pq.pop();
		for(int i=0;i<v[cv].size();i++)
		{
			int nw = v[cv][i].first;
			int nv = v[cv][i].second;
			if(weight[nv]>nw+cw&&path[cv][nv]==0)
			{
				weight[nv] = nw+cw;
				pq.push({nw+cw,nv});
			}
		}
	}
}
void delPath(int start)
{
	queue<int> q;
	q.push(start);
	while(!q.empty())
	{
		int num = q.front();
		q.pop();
		for(int i=0;i<v1[num].size();i++)
		{
			int nv = v1[num][i].second;
			int nw = v1[num][i].first;
			if(weight[nv]+nw == weight[num])
			{
				q.push(nv);
				path[nv][num] = 1;
			}
		}
	}
}
int main()
{
	while(1){
		memset(path,0,sizeof(path));
		for(int i=0;i<501;i++)
		{
			v[i].clear();
			v1[i].clear();
		}
		scanf("%d %d", &n, &m);
		if(n==0&&m==0)
			break;
		int s,d;
		scanf("%d %d", &s, &d);
		for(int i=0;i<m;i++)
		{
			int U,V,P;
			scanf("%d %d %d", &U, &V, &P);
			v[U].push_back({P,V});
			v1[V].push_back({P,U});
		}
		dij(s);
		delPath(d);
		dij(s);
		if(weight[d]==INF)
			printf("-1\n");
		else
			printf("%d\n", weight[d]);
	}

	return 0;
}
