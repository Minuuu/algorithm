#include<stdio.h>
int visit[101];
int map[101][101];
int ans=0;
int n,m;
void solve(int idx){
	visit[idx]=1;
	for(int i=1;i<=n;i++)
	{
		if(visit[i]==0&&map[idx][i]==1){
			ans++;
			solve(i);
		}
	}
	return ;
}
int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		map[a][b]=1;
		map[b][a]=1;
	}
	solve(1);
	printf("%d\n", ans);
	return 0;
}
