#include<stdio.h>
#include<algorithm>
int city[101][101];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			city[i][j] = 100001;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a,&b,&c);
		if(city[a][b]==100001)
			city[a][b] = c;
		else {
			city[a][b] = std::min(city[a][b], c);
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
					continue;
				if (city[i][j] > city[i][k] + city[k][j])
					city[i][j] = city[i][k] + city[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (city[i][j] == 100001)
				city[i][j] = 0;
			printf("%d ", city[i][j]);
		}
		printf("\n");
	}
	return 0;
}
