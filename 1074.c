#include<stdio.h>
#include<math.h>
int sum=0;
int flag=0;
void solve(int sx, int sy, int ex, int ey, int r, int c)
{
	if(sx<=r&&ex>=r && sy<=c && ey>=c)
	{
		if(sx==r&&sy==c&&ex==r&&ey==c)
		{
			sum += 1;
			flag = 1;
			return ;
		}
		int tx = (ex-sx+1)/2;
		int ty = (ey-sy+1)/2;
		solve(sx,sy,sx+tx-1,sy+ty-1,r,c);
		solve(sx,sy+ty,sx+tx-1,ey,r,c);
		solve(sx+tx,sy,ex,sy+ty-1,r,c);
		solve(sx+tx,sy+ty,ex,ey,r,c);
		return ;
	}
	else
	{
		if(flag==0){
			int d = ex-sx+1;
			sum += d*d;
		}
		return ;
	}
	
}
int main()
{
	int N,r,c;
	scanf("%d %d %d", &N, &r, &c);
	N = pow(2,N);
	solve(0,0,N-1,N-1,r,c);
	printf("%d\n", sum-1);

	return 0;
}
