#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>i;j--)
		{
			printf(" ");
		}
		for(int j=0;j<(i-1)*2+1;j++)
			printf("*");
		printf("\n");

	}
	return 0;
}
