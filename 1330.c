#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d %d", &a, &b);
	char c;
	if(a>b)
		c='>';
	else if(a<b)
		c='<';
	else
		c='=';
	if(c=='=')
		printf("==");
	else
		printf("%c", c);
	return 0;
}
