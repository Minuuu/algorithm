#include<stdio.h>
#include<vector>
using namespace std;
vector<pair<int,int>> v[10001];
bool visit[10001];
int ans=0;
int fv=0;
void solve(int idx, int sum)
{
	if(sum>ans)
	{
		fv = idx;
		ans = sum;
	}
	visit[idx]=true;
	for(int i=0;i<v[idx].size();i++)
	{
		if(visit[v[idx][i].first]==false){
			solve(v[idx][i].first,sum+v[idx][i].second);
		}
	}

}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	solve(1,0);
	memset(visit,0,sizeof(visit));
	solve(fv,0);
	printf("%d\n", ans);
		
	return 0;
}
