#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[3001][4];
int parent[3001];
int cnt[3001];
int n;
int find(int num) {
	if (parent[num] == num) {
		return num;
	}
	return parent[num] = find(parent[num]);
}
void Union(int a, int b) {
	int ra = find(a);
	int rb = find(b);
	parent[ra] = rb;
}
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int val = (x1*y2 + x2*y3 + x3*y1) - (y1*x2 + y2*x3 + y3*x1);
	return val > 0 ? 1 : (val < 0 ? -1 : 0);
}

int isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int c1 = ccw(x1, y1, x2, y2, x3, y3);
	int c2 = ccw(x1, y1, x2, y2, x4, y4);
	int c3 = ccw(x3, y3, x4, y4, x1, y1);
	int c4 = ccw(x3, y3, x4, y4, x2, y2);
	if (c1*c2 <= 0 && c3*c4 <= 0) {
		if ((x1 > x3 && x1 > x4 && x2 > x3 && x2 > x4) || (x1 < x3&&x1 < x4&&x2 < x3&&x2 < x4))
			return false;
		if ((y1 > y3 && y1 > y4 && y2 > y3 && y2 > y4) || (y1 < y3&&y1 < y4&&y2 < y3&&y2 < y4))
			return false;
		return true;
	}
	return false;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
		for (int j = 1; j < i; j++) {
			if (isCross(arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[j][0], arr[j][1], arr[j][2], arr[j][3])) {
				Union(i, j);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cnt[find(i)]++;
	int group = 0;
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] != 0)
			group++;
		ans = max(ans, cnt[i]);
	}
	printf("%d\n%d\n", group, ans);
	



	return 0;
}
