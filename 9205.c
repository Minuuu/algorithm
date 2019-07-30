#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<string.h>
using namespace std;
int n;
vector<pair<int,int> > v;
int getDistance(pair<int,int> a, pair<int,int> b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}
string ans;
int visit[1001];
void dfs(int idx)
{
	if(idx==n+1)
	{
		ans="happy";
		return ;
	}
	for(int i=0;i<v.size();i++)
	{
		if(visit[i]==0){
			if(getDistance(v[idx],v[i])<=1000)
			{
				visit[i]=1;
				dfs(i);
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		memset(visit,0,sizeof(visit));
		v.clear();
		int x,y;
		ans="sad";
		for(int i=0;i<n+2;i++)
		{
			scanf("%d %d", &x, &y);
			v.push_back(make_pair(x,y));
		}
		dfs(0);
		cout<<ans<<endl;
	}

	return 0;
}
