#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	//int x = (n)*(n-1)/2+1
	int x=1;
	int sum;
	while(1)
	{
		sum = x*(x-1)/2+1;
		if(sum>n)
			break;
		x++;
	}
	x--;
	sum=x*(x-1)/2+1;
	//printf("%d %d\n", sum,x);
	if(x%2==0)
		printf("%d/%d\n", 1+(n-sum),x-(n-sum));
	else
		printf("%d/%d\n", x-(n-sum),1+(n-sum));
	return 0;
}
