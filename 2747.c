#include<stdio.h>
int d[50];
int main()
{
	int n;
	scanf("%d", &n);
	d[1]=0;
	d[2]=1;
	for(int i=3;i<=n+1;i++)
	{
		d[i]=d[i-1]+d[i-2];
	}
	printf("%d\n", d[n+1]);
	return 0;
}
