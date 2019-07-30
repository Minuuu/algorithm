#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	
	int idx = 0;
	int num = n;
	for (int i = 2; i <= n; i++)
	{
		if (num%i == 0) {
			printf("%d\n", i);
			num /= i;
			i--;

		}
	}
	
	return 0;
}
