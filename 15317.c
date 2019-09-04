#include<stdio.h>
#include<algorithm>
using namespace std;
int c[100001];
int s[100001];
int n,m,x;
int main()
{
	scanf("%d %d %d", &n, &m, &x);
	for(int i=0;i<n;i++)
		scanf("%d", c+i);
	for(int i=0;i<m;i++)
		scanf("%d", s+i);
	sort(c,c+n);
	sort(s,s+m);

	int l = 0;
	int r = min(n,m);
	int ans = -1;
	while(l<=r)
	{
		int mid = (l+r)/2;
		printf("%d %d %d\n", m, mid, m-mid);
		int val = x;
		for(int i=0;i<mid;i++)
		{
			if(c[i]>s[m-mid+i])
				val -= c[i]-s[m-mid+i];
			if(val<0)
				break;
		}
		if(val>=0)
		{
			ans = mid;
			l = mid+1;
		}
		else
			r = mid-1;
	}
	printf("%d\n", ans);
	return 0;
}
