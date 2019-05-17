#include<stdio.h>
int main()
{
	int n,x;
	int arr[10000];
	scanf("%d %d", &n, &x);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i]<x)
			printf("%d ",arr[i]);
	}
	return 0;
}
