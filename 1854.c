#include<stdio.h>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
vector<pair<int, int>> vv[1001];
priority_queue<int> path[1001];
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> iq;
void solve(int start, int k)
{
	iq.push({ 0,start });
	path[start].push(0);
	while (!iq.empty())
	{
		int cw = iq.top().first;
		int cv = iq.top().second;
		iq.pop();
		for (int i = 0; i < vv[cv].size(); i++) {
			int nw = vv[cv][i].first;
			int nv = vv[cv][i].second;
			if (path[nv].size() < k) {
				path[nv].push(cw + nw);
			}
			else if (path[nv].top() > nw + cw) {
				path[nv].pop();
				path[nv].push(nw + cw);
			}
			else
				continue;
			iq.push({cw+nw ,nv });
		}
	}
}
int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vv[a].push_back({ c,b });
	}
	solve(1, k);
	
	for (int i = 1; i <= n; i++)
	{
		if (path[i].size()==k) {
			printf("%d\n", path[i].top());
		}
		else {
			printf("-1\n");
		}
	}
	return 0;
}
