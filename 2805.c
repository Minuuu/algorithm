#include<stdio.h>
long long tree[1000001];
int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	long long left=0;
	long long right=0;
	long long res=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld", &tree[i]);
		if(right<tree[i])
			right=tree[i];
	}
	while(left<=right)
	{
		long long mid = (left+right)/2;
		long long tot=0;
		for(int i=0;i<n;i++)
			if(mid<tree[i])
				tot+=tree[i]-mid;
		if(tot>=m)
		{
			if(res<mid)
				res = mid;
			left = mid+1;
		}
		else
			right = mid -1;
	}
	printf("%lld\n", res);
	return 0;
}
