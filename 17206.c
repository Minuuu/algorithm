#include<stdio.h>
int c3[30000];
int c7[15000];
int main()
{
	int t,n;
	scanf("%d", &t);
	int n3=80000/3;
	int n7=80000/7;
	int sum=0;
	for(int i=1;i<=n3;i++)
	{
		c3[i]=sum+i*3;
		sum+=i*3;
	}
	sum=0;
	for(int i=1;i<=n7;i++)
	{
		if(i%3!=0){
			c7[i]=sum+i*7;
			sum+=i*7;
		}
		else
			c7[i]=c7[i-1];
	}
	for(int i=0;i<t;i++)
	{
		scanf("%d", &n);
		sum=0;
		printf("%d\n", c3[n/3]+c7[n/7]);
	}

	return 0;
}
