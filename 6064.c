#include<stdio.h>
int gcd(int a, int b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int M,N,x,y;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		int g = gcd(M,N);
		int destroy = M*N/g;
		int cnt = x;
		int tmp = x;
		while(cnt<=destroy)
		{
			if((tmp-1)%N+1==y)
				break;
			tmp+=M;
			cnt +=M;
		}
		if(cnt>destroy)
			cnt = -1;
		printf("%d\n", cnt);
	}
	return 0;
}
