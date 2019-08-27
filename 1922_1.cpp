#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int parent[1001];
int findNode(int num){
	if(parent[num]==num)
		return num;
	return parent[num] = findNode(parent[num]);
}
void Union(int a, int b)
{
	parent[findNode(b)] = findNode(a);
}
vector<pair<int, pair<int,int>>> v;
int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({c,{a,b}});
	}
	sort(v.begin(),v.end());
	int ans = 0;
	for(int i=0;i<m;i++)
	{
		if(findNode(v[i].second.first)!=findNode(v[i].second.second))
		{
			Union(v[i].second.first,v[i].second.second);
			ans+=v[i].first;
		}
	}
	return 0;
}