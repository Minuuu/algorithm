#include<stdio.h>
int main()
{
	int N;
	scanf("%d", &N);
	int ball=1;
	for(int i=0;i<N;i++)
	{
		int a,b;
		scanf("%d %d", &a,&b);
		if(a==ball)
			ball=b;
		else if(b==ball)
			ball=a;
	}
	printf("%d", ball);
	return 0;
}
