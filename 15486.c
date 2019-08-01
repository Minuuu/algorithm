#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v;
int dp[1500005];
int n;
int dfs(int idx)
{
	if(idx>=n)
	{
		return 0;
	}
	int &ret = dp[idx];
	if(ret!=-1)
		return ret;
	int r1,r2=-1;
	r1 = dfs(idx+1);
	if(idx+v[idx].first<=n){
		r2 = dfs(idx+v[idx].first)+v[idx].second;
	}
	ret = max(r1,r2);


	return ret ;
}
int main()
{	
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		pii p;
		scanf("%d %d", &p.first, &p.second);
		v.push_back(p);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n", dfs(0));




	return 0;
}
