#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=2*n-1;i++)
	{
		if(i<=n){
			for(int j=1;j<=n-i;j++)
				printf(" ");
			for(int j=1;j<=(i-1)*2+1;j++)
				printf("*");
		}
		else{
			for(int j=n;j<i;j++)
				printf(" ");
			for(int j=1;j<=(2*n-(i+1))*2+1;j++)
				printf("*");
		}
		printf("\n");

	}
	return 0;
}
