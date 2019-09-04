#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[500001]={0,};
int visit[20000005]={0,};
int main()
{

	int n,m;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", a+i);
	sort(a,a+n);
	scanf("%d", &m);
	memset(visit,-1,sizeof(visit));
	for(int j=0;j<m;j++)
	{
		int num;
		scanf("%d", &num);
		if(visit[num+10000000]!=-1)
		{
			printf("%d ", visit[num+10000000]);
			continue;
		}
		int l=0;
		int r = n-1;
		int idx = -1;
		while(l<=r)
		{
			int mid = (l+r)/2;
			if(a[mid]>num)
				r = mid - 1;
			else if(a[mid]<num)
				l = mid + 1;
			else
			{
				idx = mid;
				break;
			}
		}
		int cnt = 0;
		if(idx!=-1){
			for(int i = idx;i>=0;i--)
			{
				if(a[idx]==a[i])
					cnt++;
				else
					break;
			}
			for(int i=idx+1;i<n;i++)
			{
				if(a[i]==a[idx])
					cnt++;
				else
					break;
			}
		}
		visit[num+10000000] = cnt;
		printf("%d ", cnt);
	}
	

	return 0;
}
