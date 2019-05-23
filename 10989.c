#include<stdio.h>
int main()
{
	int arr[10001]={0,};
	int n,num;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &num);
		arr[num]++;
	}
	printf("\n");
	for(int i=1;i<=10000;i++)
	{
		if(arr[i]!=0)
		{
			for(int j=1;j<=arr[i];j++)
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}
