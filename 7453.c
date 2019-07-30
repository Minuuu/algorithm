#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v1, v2;
int main()
{
	int n;
	scanf("%d", &n);
	int a[4000];
	int b[4000];
	int c[4000];
	int d[4000];
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v1.push_back(a[i] + b[j]);
			v2.push_back(c[i] + d[j]);
		}
	}
	long long ans = 0;
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for (int i = 0; i < v1.size(); i++) {
		int high = upper_bound(v2.begin(), v2.end(), -v1[i])-v2.begin();
		int low = lower_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		ans += high - low;
	}
	printf("%lld\n", ans);
	return 0;
}
