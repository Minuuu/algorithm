#include<stdio.h>
int arr[100001];
int sum[100001];
int main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	sum[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		sum[i] = sum[i - 1] + arr[i];
	}
	
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b] - sum[a-1]);
	}

	return 0;
}
