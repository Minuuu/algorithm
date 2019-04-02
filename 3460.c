#include<stdio.h>
int main()
{
	int t;
	int n;
	scanf("%d", &t);
		while(t--){
	scanf("%d", &n);
	int tmp=1;

	for(int i=0;i<32;i++)
	{
		int a = n|tmp;
		if(a==n)
			printf("%d ", i);
		tmp = tmp<<1;
	}
	}
	return 0;
}
