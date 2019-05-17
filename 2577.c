#include<stdio.h>
int main()
{
	int a,b,c;
	int mul=1;
	int arr[10]={0,};
	scanf("%d %d %d", &a, &b, &c);
	mul=a*b*c;
	while(mul!=0)
	{
		arr[mul%10]++;
		mul/=10;
	}
	for(int i=0;i<10;i++)
		printf("%d\n", arr[i]);
	return 0;
}
