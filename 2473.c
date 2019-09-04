#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<limits.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d", &n);
	ll arr[5001]={0,};
	for(int i=0;i<n;i++)
		scanf("%lld", arr+i);
	sort(arr,arr+n);
	ll res = LLONG_MAX;
	long long ans[3]={0,};
	for(int i=0;i<n-2;i++)
	{
		ll fix = arr[i];
		int l = i+1;
		int r = n-1;
		while(l<r)
		{
			ll sum = arr[l]+arr[r]+fix;
			if(sum<0){
				if(abs(res)>abs(sum))
				{
					res = sum;
					ans[0] = fix;
					ans[1] = arr[l];
					ans[2] = arr[r];
				}
				l++;
			}
			else if(sum>0)
			{
				if(abs(res)>abs(sum))
				{
					res = sum;
					ans[0] = fix;
					ans[1] = arr[l];
					ans[2] = arr[r];
				}
				r--;
			}
			else{
				ans[0] = fix;
				ans[1] = arr[l];
				ans[2] = arr[r];
				printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
				return 0;
			}
		}
	}
	printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
	return 0;
}
