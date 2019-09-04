#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> v;
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		v.push_back({b,a});
	}
	sort(v.begin(),v.end());
	int cnt = 1;
	int last = v[0].fisrt;
	for(int i=1;i<v.size();i++)
	{
		if(last<=v[i].second)
		{
			last = v[i].first;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
