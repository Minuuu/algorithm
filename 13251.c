#include<stdio.h>
#include<string.h>

int main()
{
	int m, k;
	int arr[51] = { 0, };
	
	scanf("%d", &m);
	int stone = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", arr+i);
		stone += arr[i];
	}

	scanf("%d", &k);
	long long sum = 0;
	double ans = 0;
	for (int i = 0; i < m; i++)
	{
		if (arr[i] < k)
			continue;
		double tmp = 1;
		for (int j = 0; j < k; j++) {
			tmp *= (double)(arr[i] - j) / (stone - j);
		}
		ans += tmp;
	}
	
	
	printf("%.15lf", ans);
	return 0;
}

