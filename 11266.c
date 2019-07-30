#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int visit[10001];
int order_num[10001];
int order_cnt=1;
vector<int> nv[10001];
vector<int> solution;
int cut[10001];
/*
7 7
1 4
4 5
5 3
1 6
6 7
2 7
7 3
*/
int findDot(int idx, int root)
{
	order_num[idx] = order_cnt++;
	visit[idx] = 1;
	int ret = order_num[idx];
	int child = 0;
	for (int i = 0; i < nv[idx].size(); i++)
	{
		if (visit[nv[idx][i]] == 0) {
			child++;
			int low = findDot(nv[idx][i], 0);
			if (root == 0 && order_num[idx] <= low)
			{
				cut[idx] = 1;
			}
			ret = min(low, ret);
		}
		else {
			ret = min(ret, order_num[nv[idx][i]]);
		}
	}
	if (root == 1 && child >= 2) {
		cut[idx] = 1;
	}
	return ret;
}
int main()
{
	int v, e;
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		nv[a].push_back(b);
		nv[b].push_back(a);
	}
	for (int i = 1; i <= v; i++)
	{
		if(visit[i]==0)
			findDot(i, 1);
	}
	int ans = 0;
	for (int i = 1; i <= v; i++)
		if (cut[i]) {
			ans++;
		}
	printf("%d\n", ans);
    for (int i = 1; i <= v; i++)
		if (cut[i]) {
			ans++;
			printf("%d ", i);
		}
	return 0;
}
