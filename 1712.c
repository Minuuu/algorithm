#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	long long cnt=0;
	// a+bx < cx
	// x(c-b)>a
	if(b>=c)
		cnt=-1;
	else
	{
		cnt = a/(c-b)+1;
	}
	printf("%lld\n", cnt);
	return 0;
}
