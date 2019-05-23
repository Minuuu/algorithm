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
	int a,b,res;
	scanf("%d %d", &a, &b);
	if(a>b)
		res = gcd(a,b);
	else
		res = gcd(b,a);
	printf("%d\n%d", res, b*a/res);
	return 0;
}
