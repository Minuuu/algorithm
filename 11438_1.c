#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v[100001];
int depth[100001];
int visit[100001];
int parent[21][100001];
int maxD = -1;
void dfs(int idx, int dep)
{
	depth[idx] = dep;
	if(dep>maxD)
		maxD = dep;
	visit[idx] = 1;
	for(int i=0;i<v[idx].size();i++)
	{
		if(!visit[v[idx][i]])
		{
			parent[0][v[idx][i]] = idx;
			dfs(v[idx][i],dep+1);
		}
	}
}
void updateParent(int n)
{
	for(int i=1;i<21;i++)
	{
		for(int j=1;j<=n;j++)
		{
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}
}
int lcd(int a, int b)
{
	if(depth[a]>depth[b])
		swap(a,b);
	for(int i=20;i>=0;i--)
	{
		if(depth[b]-depth[a]>=(1<<i))
			b = parent[i][b];
	}
	if(a==b)
		return a;
	for(int i=20;i>=0;i--)
	{
		if(parent[i][a]!=parent[i][b]){
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];

}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
	updateParent(n);
	int m;
	scanf("%d", &m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lcd(a,b));
	}


	return 0;
}
