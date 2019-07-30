#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int parent[21][100001];
vector<int> v1[100001];
int visit[100001];
int dep[100001];
int maxdepth = -1;
void dpt(int idx, int depth)
{
	dep[idx] = depth;
	if (depth > maxdepth)
		maxdepth = depth;
	visit[idx] = 1;
	for (int i = 0; i < v1[idx].size(); i++)
	{
		if (!visit[v1[idx][i]]) {
			parent[0][v1[idx][i]] = idx;
			dpt(v1[idx][i], depth + 1);
		}
	}
}
void updateParent(int n)
{
	int num = log2(maxdepth) + 1;

	for (int k = 1; k < num; k++)
	{
		for (int i = 1; i <= n; i++) {
			parent[k][i] = parent[k - 1][parent[k - 1][i]];
		}
	}
	/*
	for (int i = 1; i <= n; i++)
		printf("%2d ", i);
	printf("\n");
	
	for (int k = 0; k < num; k++)
	{
		for (int i = 1; i <= n; i++) {
			printf("%2d ", parent[k][i]);
		}
		printf("\n");
	}
	*/

}
int lcd(int a, int b)
{
	if (dep[a] > dep[b])
		swap(a, b);
	
	int diff = dep[b] - dep[a];
	for (int i = log2(dep[b] - dep[a]); i >= 0; i--) {
		if (dep[b] - dep[a] >= (1 << i))
			b = parent[i][b];
	}
	if (a == b)
		return a;
	else {
		for (int i = 20; i >= 0; i--) {
			if (parent[i][a] != parent[i][b]) {
				a = parent[i][a];
				b = parent[i][b];
			}
		}
		return parent[0][a];
	}
}
int main()
{
	int n,m;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v1[a].push_back(b);
		v1[b].push_back(a);
	}
	dpt(1, 0);
	updateParent(n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n",lcd(a, b));
	}

	return 0;
}
