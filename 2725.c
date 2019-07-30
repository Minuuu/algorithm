#include<stdio.h>
#include<algorithm>
int GCD(int x, int y) {
	if (x%y == 0)
		return y;
	return GCD(y, x%y);
}
int disjoint(int x, int y) {
	if (GCD(x, y) == 1)
		return 1;
	return 0;
}

int count[1001];
int main()
{
	int c;
	scanf("%d", &c);
	int num = -1;
	int ans = 0;
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (disjoint(i, j)) {
				ans++;
			}
		}
		count[i] = ans;
	}
	while (c--)
	{
		int n;
		scanf("%d", &n);
		
		printf("%d\n", count[n]*2+3);
	}
	return 0;
}
