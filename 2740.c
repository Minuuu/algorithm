#include<stdio.h>
int map[101][101];
int map1[101][101];
int ans[101][101];
int main()
{
	int n,m,c;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			scanf("%d", &map[i][j]);
	}
	scanf("%d %d", &m, &c);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<c;j++)
			scanf("%d", &map1[i][j]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<c;j++)
		{
			for(int k=0;k<m;k++)
			{
				ans[i][j] += map[i][k]*map1[k][j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<c;j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}
