#include<stdio.h>
int main()
{
	int num;
	int cnt=0;
	scanf("%d", &num);
	int sum=num;

	while(1)
	{
		int a = sum/10;
		int b = sum%10;
		sum = b*10+(a+b)%10;
		cnt++;
		if(sum==num)
			break;
	
	}
	printf("%d\n", cnt);
	return 0;
}
