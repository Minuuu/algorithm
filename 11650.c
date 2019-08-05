#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int>> v;
bool comp(pair<int,int> a, pair<int,int> b)
{
	if(a.first==b.first)
		return a.second<b.second;
	return a.first<b.first;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end(),comp);
	for(auto i : v)
		printf("%d %d\n", i.first, i.second);
	return 0;
}
