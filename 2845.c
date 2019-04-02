#include<stdio.h>
int main()
{
	int N,M;
	int arr[5];
	scanf("%d %d", &N, &M);
	for(int i=0;i<5;i++){
		scanf("%d", &arr[i]);
		printf("%d ", arr[i]-N*M);
	}
	return 0;
}
