#include<stdio.h>
long d[100];
int main()
{
	int n;
	scanf("%d", &n);
	d[0]=0;
	d[1]=1;
	for(int i=2;i<=n;i++)
	{
		d[i]=d[i-1]+d[i-2];
	}
	printf("%d\n", d[n]);
	return 0;
}
