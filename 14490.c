#include<stdio.h>
int gcd(int a, int b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	int a,b;
	scanf("%d:%d", &a,&b);
	int g= gcd(a,b);
	printf("%d:%d\n", a/g, b/g);
	return 0;
}
