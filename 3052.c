#include<stdio.h>
int main()
{
	int arr[42]={0,};
	for(int i=0;i<10;i++)
	{
		int num;
		scanf("%d", &num);
		arr[num%42]++;
	}
	int cnt=0;
	for(int i=0;i<42;i++)
		if(arr[i]!=0)
			cnt++;
	printf("%d\n", cnt);
	return 0;
}
