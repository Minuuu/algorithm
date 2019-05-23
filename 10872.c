#include<stdio.h>
int main()
{
	int n;
	long long ans=1;
	scanf("%d", &n);
	for(int i=n;i>=1;i--)
		ans*=i;
	printf("%ld\n", ans);
	return 0;
}
