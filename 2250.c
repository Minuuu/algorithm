#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> v[10001];
int parent[10001];
int cnt=1;
int mmin[10001];
int mmax[10001];
void dfs(int idx, int depth)
{
	int l = v[idx][0].first;
	int r = v[idx][0].second;
	if(l!=-1)
		dfs(l,depth+1);
	mmin[depth] = min(mmin[depth],cnt);
	mmax[depth] = max(mmax[depth],cnt);
	cnt++;
	if(r!=-1)
		dfs(r,depth+1);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({b,c});
		parent[b]=a;
		parent[c]=a;
	}
	int root = -1;
	for(int i=1;i<=n;i++)
	{
		mmin[i] = 987654321;
		if(parent[i]==0)
		{
			root = i;
		}
	}
	dfs(root,1);
	int res = mmax[1]-mmin[1]+1;
	int lvl = 1;
	for(int i=2;i<=n;i++)
	{
		int tmp = mmax[i]-mmin[i]+1;
		if(tmp>res)
		{
			res = tmp;
			lvl = i;
		}
	}
	printf("%d %d\n", lvl, res);
	return 0;
}
