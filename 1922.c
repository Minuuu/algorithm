#include<stdio.h>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//vector<pair<int,int>> v[1001];

vector<pair<int,pair<int,int>>> com;
int pa[1001];
int findNode(int num) {
	if (pa[num] == num)
		return num;
	else
		return pa[num] = findNode(pa[num]);
}
void UnionNode(int a, int b) {
	int ra = findNode(a);
	int rb = findNode(b);
	pa[rb] = ra;
}
int main()
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		com.push_back({ c,make_pair(a,b) });
	}
	sort(com.begin(), com.end());
	for (int i = 1; i <= n; i++) {
		pa[i] = i;
	}
	for (int i = 0; i < com.size(); i++) {
		if (findNode(com[i].second.first) != findNode(com[i].second.second)) {
			UnionNode(com[i].second.first, com[i].second.second);
			ans += com[i].first;
		}
	}
	
	printf("%d\n", ans);

	return 0;
}
