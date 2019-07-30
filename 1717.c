#include<stdio.h>
#include<vector>
using namespace std;
int ar[1000001];
int find(int num)
{
	if (ar[num] == num)
		return num;
	else {
		return ar[num] = find(ar[num]);
	}

}
void Union(int a, int b)
{
	int aR = find(a);
	int bR = find(b);
	ar[bR] = aR;
	return;
}

int main()
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
		ar[i] = i;
	for (int i = 0; i < m; i++) {
		int d, a, b;
		scanf("%d %d %d", &d, &a, &b);
		if (d == 0) {
			Union(a, b);
		}
		else {
			int aroot = find(a);
			int broot = find(b);
			if (aroot == broot)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

}
