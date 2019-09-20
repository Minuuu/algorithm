#include<stdio.h>
int key[21][21];
int lock[21][21];
int m,n;
void solve()
{

}
int main()
{
	scanf("%d %d", &m, &n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d", &key[i][j]);
			scanf("%d", &lock[i][j]);
		}
	}
	solve();
	return 0;
}
