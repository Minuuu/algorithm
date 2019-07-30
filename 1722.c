#include<stdio.h>
#include<vector>
using namespace std;
vector<long long> v;
int main()
{
	int n,K;
	long long res = 1;
	int visit[21] = { 0, };
	long long fac[21] = { 0, };
	scanf("%d", &n);
	scanf("%d", &K);
	fac[0] = 1;
	for (int i = 1; i <=n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	

	if (K == 1)
	{
		long long k;
		scanf("%lld", &k);
		for (int i = 1; i <= n; i++)
		{
			int cnt = 1;
			for (int j = 1; j <= n; j++) {
				if (visit[j])
					continue;
				if (cnt*fac[n-i] >= k) {
					k -= (cnt-1)*fac[n - i];
					visit[j] = 1;
					v.push_back(j);
					break;
				}
				cnt++;
			}
		}
		for (int i = 0; i < v.size(); i++)
			printf("%lld ", v[i]);
		printf("\n");
		
	}
	else if(K==2) {
		int arr[21] = { 0, };
		long long l = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", arr + i);
			int cnt = 0;
			for (int j = 1; j < arr[i]; j++) {
				if (visit[j] == 0)
					cnt++;
			}
			l += cnt*fac[n - i];
			visit[arr[i]] = 1;
		}
		printf("%lld\n", l);

	}
	return 0;
}
