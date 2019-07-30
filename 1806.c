#include<stdio.h>
#include<limits.h>
int main()
{
	int n, m;
	int arr[100001] = { 0, };
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	int l = 0, r = 0;
	int num = 0;
	int sum = 0;
	int ans = INT_MAX;
	while (l <= r&&r<=n)
	{
		if (sum >= m)
		{
		
			//printf("len: %d\n", r - l);
			if(ans>r-l)
				ans = r - l;
			sum -= arr[l];
			l++;
		}
		else
		{
			sum += arr[r];
			r++;
		}
	}
	if (ans == INT_MAX)
		ans = 0;
	printf("%d\n", ans);
	return 0;
}
