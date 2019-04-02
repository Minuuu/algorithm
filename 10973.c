#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int arr[10001];
int N;
int main()
{
	scanf("%d", &N);
	int tmp=0;
	int i;
	for(i=1;i<=N;i++)
	{
		scanf("%d", &arr[i]);
	}
	for(i=1;i<=N;i++)
	{
		if(arr[i]<arr[i-1])
			tmp=i-1;
	}
	if(tmp==0)
	{
		printf("-1");
		return 0;
	}
	//printf("%d\n", tmp);

	for(i=N;i>=tmp;i--)
	{
		if(arr[tmp]>arr[i])
		{
			swap(arr[tmp],arr[i]);
			break;
		}
	}
	sort(arr+tmp+1,arr+N+1,greater<int>());
	for(int i=1;i<=N;i++)
		printf("%d ", arr[i]);

	return 0;
}
