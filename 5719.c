#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<functional>
#define INF 987654321
using namespace std;
vector<pair<int, int>> v[501], v1[501];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> q;
int dist[501];
int visit[501][501];
void dijkstra(int start, int vertex) {
	memset(dist, 0, sizeof(dist));
	for (int i = 0; i < vertex; i++)
		dist[i] = INF;
	dist[start] = 0;
	q.push({ 0,start });
	while (!q.empty())
	{
		int cv = q.top().second;
		int cw = q.top().first;
		q.pop();
		if (dist[cv] < cw)
			continue;
		for (int i = 0; i < v[cv].size(); i++)
		{
			int nv = v[cv][i].second;
			int nw = v[cv][i].first;
			if (visit[cv][nv]==0&&dist[nv] > nw + cw) {
				dist[nv] = nw + cw;
				q.push({ dist[nv],nv });
			}
		}
	}
	return;
}
void erase(int start)
{
	queue<int> q1;
	q1.push(start);
	while (!q1.empty())
	{
		int num = q1.front();
		q1.pop();
		for (int i = 0; i < v1[num].size(); i++)
		{
			int nv = v1[num][i].second;
			int nw = v1[num][i].first;
			if (dist[nv] + nw == dist[num]) {
			//	printf("??\n");
				visit[nv][num] = 1;
				q1.push(nv);
			}
		}
	}

	
}
int main()
{
	while (1) {
		int n, m;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;
		int s, d;
		for (int i = 0; i < 501; i++)
		{
			v[i].clear();
			v1[i].clear();
		}
		memset(visit, 0, sizeof(visit));
		scanf("%d %d", &s, &d);
		for (int i = 0; i < m; i++)
		{
			int U, V, P;
			scanf("%d %d %d", &U, &V, &P);
			v[U].push_back({ P,V });
			v1[V].push_back({ P,U });
		}
		dijkstra(s, n);
		/*
		for (int i = 0; i < n; i++)
			printf("%d ", dist[i]);
		printf("\n");
		
		printf("\n");
		*/
		erase(d);
		dijkstra(s, n);
		if (dist[d] == INF)
			printf("-1\n");
		else
			printf("%d\n", dist[d]);
	}
	return 0;
}
