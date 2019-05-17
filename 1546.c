#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	double max=-1;
	double arr[1000];
	double sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lf", &arr[i]);
		if(arr[i]>max)
			max=arr[i];
	}
	for(int i=0;i<n;i++)
	{
		arr[i]=(arr[i]/max)*100;
		sum+=arr[i];
	}
	printf("%lf\n", (double)(sum/n));

	return 0;
}
