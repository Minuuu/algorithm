#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d %d", &a, &b);
	if(b<45)
	{
		if(a==0)
			a=23;
		else
			a-=1;
		b=60-(45-b);
	}
	else{
		b-=45;
	}
	printf("%d %d\n", a,b);
	return 0;
}
