#include<stdio.h>
int gcd(int a, int b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int a,b,res;
		scanf("%d %d", &a, &b);
		if(a>b)
			res = gcd(a,b);
		else
			res = gcd(b,a);
		printf("%d\n", a*b/res);
	}
	return 0;
}
