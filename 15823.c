#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[100001];
int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	int l=1;
	int r = n;
	int ans = -1;
	while(l<=r)
	{
		int mid = (l+r)/2;
		int cnt = 0;
		int chk[500001]={0,};
		int idx = 1;
		for(int i=1;i<=n;i++)
		{
			if(chk[arr[i]]>0&&chk[arr[i]]>=idx)
			{
				idx = chk[arr[i]]+1;
			}
			chk[arr[i]] = i;
			if(i-idx+1==mid)
			{
				cnt++;
				idx = i+1;
			}
			if(cnt==m)
				break;
		}
		if(cnt==m)
		{
			ans = max(ans,mid);
			l = mid+1;
		}
		else
			r = mid-1;
	}
	printf("%d\n", ans);
	return 0;
}
