#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d", &n);
	int arr[10001]={0,};
	for(int i=0;i<n;i++)
		scanf("%d", arr+i);
	scanf("%d", &m);

	int l = 1;
	int r = m;
	int ans = -1;
	while(l<=r)
	{
		int mid = (l+r)/2;
		int sum=0;
		int max = -1;
		for(int i=0;i<n;i++)
		{
			sum+=mid;
			if(mid>arr[i])
				sum-=mid-arr[i];
			if(mid<=arr[i])
				max = mid;
			else{
				if(max<arr[i])
					max = arr[i];
			}
		}
		if(sum>m)
		{
			r = mid-1;
		}
		else{
			l = mid+1;		
			if(ans<max)
				ans = max;
		}
	}
	printf("%d\n", ans);
	return 0;
}
