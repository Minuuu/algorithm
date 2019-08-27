#include<stdio.h>
int a,b,c;
long long solve(int aa, int bb)
{
	if(bb==0)
		return 1;
	long long ret = solve(aa,bb/2);
	ret = ((ret%c)*(ret%c))%c;
	if(bb%2==1)
		ret = (ret%c*aa%c)%c;
	return ret;
}
int main()
{
	scanf("%d %d %d", &a, &b, &c);
	printf("%lld\n", solve(a,b)%c);
	return 0;
}
