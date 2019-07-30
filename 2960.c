#include<stdio.h>
int pr[1001];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	for (int i = 2; i <= n; i++)
		pr[i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for(int j=i;j<=n;j+=i)
			if (pr[j] == 1) {
				pr[j] = 0;
				k--;
				if (!k)
				{
					printf("%d\n", j);
					return 0;
				}
			}
	}
	return 0;
}
