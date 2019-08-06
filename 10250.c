#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	int h,w,n;
	while(t--){
		//1 10 9
		scanf("%d %d %d", &h, &w, &n);
		int num = n%h;
		int num1 = n/h+1;
		if(num==0)
		{
			num=h;
			num1--;
		}
		
		if(num1>=1&&num1<=9)
			printf("%d0%d\n", num,num1);
		else
			printf("%d%d\n", num,num1);

	}

	return 0;
}
