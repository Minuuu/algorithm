#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[1000005];
int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	for(int i=0;i<n;i++)
	{
		scanf("%d", arr+i);
	}
	int idx = lower_bound(arr,arr+n,k)-arr-1;

	int ans=0;
	while(1)
	{
		ans+=k/arr[idx];
		k = k%arr[idx];
		idx--;
		if(k==0||idx<0)
			break;
	}
	printf("%d\n", ans);

	return 0;
}
