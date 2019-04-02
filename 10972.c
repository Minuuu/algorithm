#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int N;
int arr[10001];
int main()
{
	int min=0;
	int tmp=0;
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%d", &arr[i]);
	for(int i=1;i<=N;i++)
	{
		if(arr[i-1]<arr[i])
		{
			tmp=i-1;
		}
	}
	if(tmp==0)
	{
		printf("-1");
		return 0;
	}
	//printf("tmp: %d\n", tmp);
	for(int i=N;i>=tmp;i--)
	{
		if(arr[i]>arr[tmp]){
			std::swap(arr[tmp],arr[i]);
			break;
		}
	}
//	for(int i=1;i<=N;i++)
//		printf("%d ", arr[i]);
//	printf("tm: %d\n", tmp+1);
	sort(arr+tmp+1,arr+N+1);
	for(int i=1;i<=N;i++)
		printf("%d ", arr[i]);
	return 0;
}
