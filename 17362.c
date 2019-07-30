#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int a=1;
	while(1)
	{
		int d = 8*a-7;
		if(d>=n)
			break;
		a++;
	}
	int diff = 8*a-7-n+1;
	int ans = diff;
	switch(diff){
		case 2:
		case 8:
			ans = 2;
			break;
		case 7:
		case 3:
			ans =3;
			break;
		case 6:
		case 4:
			ans=4;
			break;
	}
	printf("%d\n", ans);
	return 0;
}
