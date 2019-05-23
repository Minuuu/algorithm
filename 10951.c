#include<stdio.h>
int main()
{
	int a,b;
	setbuf(stdout,NULL);
	while(scanf("%d %d", &a, &b)!=EOF)
		printf("%d\n", a+b);
	return 0;
}
