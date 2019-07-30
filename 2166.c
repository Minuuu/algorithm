#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
vector<pair<long long, long long>> v;
long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long a = x1*y2 - y1*x2;
	long long b = x2*y3 - y2*x3;
	long long c = x3*y1 - y3*x1;
	return  a + b + c;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		long long a, b;
		scanf("%lld %lld", &a, &b);
		v.push_back(make_pair(a, b));
	}
	long long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += (ccw(v[i].first, v[i].second, v[0].first, v[0].second, v[(i + 1) % v.size()].first, v[(i + 1) % v.size()].second));
	}
	sum = abs(sum);
	if (sum % 2 == 0) {
		printf("%lld.0\n", sum / 2);
	}
	else
		printf("%lld.5\n", sum / 2);

	return 0;
}
