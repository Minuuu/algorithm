#include<stdio.h>
int main()
{
	int num;
	char c;
	scanf("%d", &num);
	if(num>=90&&num<=100){
		c='A';
	}
	else if(num>=80)
		c='B';
	else if(num>=70)
		c='C';
	else if(num>=60)
		c='D';
	else c='F';
	printf("%c\n",c);
	return 0;
}
