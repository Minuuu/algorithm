#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;
vector<int> v[32001];
int visit[32001];
void dfs(int num)
{
	visit[num] = 1;
	for (int i = 0; i < v[num].size(); i++) {
		if (visit[v[num][i]] == 0)
			dfs(v[num][i]);
	}
	q.push(num);
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if (!visit[i])
			dfs(i);
	while (!q.empty()) {
		printf("%d\n",q.front());
		q.pop();
	}
	return 0;
}
