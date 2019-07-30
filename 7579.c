#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n, m;
int mem[105];
int cost[105];
int d[105][6000];
int ans=987654321;
int cnt = 0;
int go(int idx, int c)
{
	if (idx == n+1)
		return 0;
	int &ret = d[idx][c];

	if (ret != -1)
		return ret;
	cnt++;
	ret = go(idx + 1, c);
	if(c>=cost[idx])
		ret = max(ret, mem[idx]+go(idx + 1,  c - cost[idx]));
	
	return ret;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", mem + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", cost + i);
	memset(d, -1, sizeof(d));
	for(int i=0;i<=6000;i++){
		if (go(1,i) >= m) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
