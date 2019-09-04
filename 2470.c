#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d", &n);
	ll arr[100001]={0,};
	for(int i=0;i<n;i++)
		scanf("%lld", arr+i);
	sort(arr,arr+n);
	int l = 0;
	int r = n-1;
	int res = 2100000000;
	int al, ar;
	while(l<r)
	{
		ll sum = arr[l]+arr[r];
		if(sum<0){
			if(abs(res)>abs(sum))
			{
				res = sum;
				al = l;
				ar = r;
			}
			l++;
		}
		else if(sum>0)
		{
			if(abs(res)>abs(sum))
			{
				res = sum;
				al = l;
				ar = r;
			}
			r--;
		}
		else{
			al = l;
			ar = r;
			break;
		}
	}
	printf("%lld %lld\n", arr[al], arr[ar]);
	return 0;
}
