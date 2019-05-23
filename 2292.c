#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int cnt=1;
	int sum=1;
	while(n!=1)
	{
		sum+=6*cnt++;
		if(sum-6*(cnt-1)+1<=n&&sum>=n)
			break;
	}
	printf("%d\n", cnt);
	return 0;
}
