#include<stdio.h>
int arr[500001];
int tmp[500001];
long long ans=0;
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void solve(int l, int r)
{
	if(r-l<=1)
	{
		if(arr[l]>arr[r])
		{
			swap(arr[l],arr[r]);
			ans++;
		}
		return ;
	}
	int mid = (l+r)/2;
	solve(l,mid);
	solve(mid+1,r);

	int li = l;
	int ri = mid+1;
	int idx = l;
	while(li<=mid&&ri<=r)
	{
		if(arr[li]>arr[ri])
		{
			tmp[idx++] = arr[ri++];
		}
		else
		{
			tmp[idx++] = arr[li++];
			ans+=ri-mid-1;
		}
	}
	while(li<=mid)
	{
		tmp[idx++] = arr[li++];
		ans+= r-mid;
	}
	//ans -= r-mid;
	while(ri<=r)
	{
		tmp[idx++] = arr[ri++];
	}
	for(int i=l;i<=r;i++)
		arr[i] = tmp[i];
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", arr+i);
	solve(0,n-1);
	printf("%lld\n", ans);
	return 0;
}
