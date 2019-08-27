#include<stdio.h>
int n;
int map[64][64];
int check(int sx, int sy, int ex, int ey)
{
	int num = map[sx][sy];
	for(int i=sx;i<=ex;i++)
	{
		for(int j=sy;j<=ey;j++)
			if(map[i][j]!=num)
				return -1;
	}
	return num;
}
void solve(int sx, int sy, int ex, int ey)
{
	int chk = check(sx,sy,ex,ey);
	if(chk!=-1)
	{
		printf("%d",chk);
		return ;
	}
	else
	{
		printf("(");
		int a = sx;
		int b = sy;
		int c = (ex-sx)/2;
		int d = (ey-sy)/2;
		solve(a,b,a+c,b+d);
		solve(a,b+d+1,a+c,ey);
		solve(a+c+1,b,ex,b+d);
		solve(a+c+1,b+d+1,ex,ey);
		printf(")");
	}
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%1d", &map[i][j]);
	solve(0,0,n-1,n-1);

	return 0;
}
