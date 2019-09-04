#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
priority_queue<int> q;
vector<pair<int,int>> v;
vector<int> c;
int N,K;
int main()
{
	scanf("%d %d", &N, &K);
	for(int i=0;i<N;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		v.push_back({a,b});
	}
	for(int i=0;i<K;i++)
	{
		int a;
		scanf("%d", &a);
		c.push_back(a);
	}
	sort(v.begin(),v.end());
	sort(c.begin(),c.end());
	int idx = 0;
	long long ans = 0;
	for(int i=0;i<K;i++)
	{
		while(v[idx].first<=c[i]&&idx<N)
		{
			q.push(v[idx++].second);
		}
		if(!q.empty())
		{
			ans += q.top();
			q.pop();
		}
	}
	printf("%lld\n", ans);
	return 0;
}
