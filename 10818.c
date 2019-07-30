#include<stdio.h>
int main()
{
	int n;
	int max=-1000001;
	int min=1000001;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		int num;
		scanf("%d", &num);
		if(num>max)
			max=num;
		if(num<min)
			min=num;
	}
	printf("%d %d\n", min, max);
}
