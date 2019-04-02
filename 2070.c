#include<stdio.h>
int main()
{
	int T;
	scanf("%d", &T);
	for(int i=1;i<=T;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		printf("#%d ", i);
		if(a<b)
			printf("<\n");
		else if(a>b)
			printf(">\n");
		else
			printf("=\n");
	}
	return 0;
}
