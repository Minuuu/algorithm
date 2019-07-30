#include<stdio.h>
#include<map>
using namespace std;
map<long long, int> mm;
int main()
{
	int t;
	int n, m;
	long long arr[1000] = { 0, };
	long long brr[1000] = { 0, };
	scanf("%d", &t);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%lld", &brr[i]);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < n-i+1; j++)
		{
			long long sum = 0;
			for (int k = j; k < j + i; k++)
				sum += arr[k];
			mm[sum]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < m-i+1; j++)
		{
			long long sum = 0;
			//printf("b: ");
			for (int k = j; k < j + i; k++)
			{
				sum += brr[k];
			//	printf("%d ", brr[k]);
			}
			//printf("\n");
			if (mm[t - sum] != 0)
				ans += mm[t - sum];
		}
	}
	printf("%lld\n", ans);
	return 0;
}
