#include<stdio.h>
#include<vector>
#define INT_MAX 987654321
using namespace std;
vector<pair<int,int>> map[501];
int weight[501];
int bfa(int start, int v, int e)
{
	for (int i = 1; i <= v; i++)
		weight[i] = INT_MAX;
	weight[start] = 0;
	int flag = 0;
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			int size = map[j].size();
			for (int k = 0; k < size; k++)
			{
				if (weight[j]!= INT_MAX && weight[map[j][k].first] > weight[j] + map[j][k].second) {
					weight[map[j][k].first] = weight[j] + map[j][k].second;
					if (i == v)
						flag = 1;
				}
			}
		}
	}
	return flag;
}
int main()
{
	int n, m;
	int a, b, c;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back({ b,c });
	}
	int chk = bfa(1, n, m);
	if (chk == 1)
		printf("-1");
	else {
		for (int i = 2; i <= n; i++)
		{
			if (weight[i] == INT_MAX)
				printf("-1\n");
			else
				printf("%d\n", weight[i]);
		}
	}
	return 0;
}
