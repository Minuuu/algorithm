#include<stdio.h>
int main()
{
	int a,b,v;
	scanf("%d %d %d", &a,&b,&v);
	//a-b)*n+a=V
	int ans;
	if( (v-a)%(a-b)==0)
		ans = (v-a)/(a-b);
	else
		ans = (v-a)/(a-b)+1;


	printf("%d\n", ans+1);
	return 0;
}
