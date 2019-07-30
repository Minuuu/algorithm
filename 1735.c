#include<stdio.h>
#include<algorithm>
int gcd(int a, int b)
{
	if (a%b == 0)
		return b;
	else {
		return gcd(b, a%b);
	}
}
int main()
{
	int a, b;
	int c, d;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	int e, f;
	int g = gcd(b, d);
	int t1 = a*d / g+c*b/g;
	int t2 = b*d / g;
	int g1 = gcd(t1, t2);


	printf("%d %d", t1/g1, t2/g1);
	return 0;
}

