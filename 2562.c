#include<stdio.h>
#include<algorithm>
int main()
{
	int arr[9];
	for(int i=0;i<9;i++)
		scanf("%d", &arr[i]);
	int *idx = std::max_element(arr,arr+9);
	printf("%d\n", *idx);
	printf("%d\n", std::distance(arr,idx)+1);
	return 0;
}
