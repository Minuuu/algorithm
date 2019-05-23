#include<stdio.h>
int chk[1000001];
int main()
{
	int m,n;
	scanf("%d %d", &m, &n);
	chk[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j*i<=n;j++)
		{
			chk[i*j]=1;
		}
	}
	for(int i=m;i<=n;i++)
		if(chk[i]!=1)
			printf("%d\n", i);
	return 0;
}
