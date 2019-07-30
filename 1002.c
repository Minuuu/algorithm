#include<stdio.h>
int main()
{
	int t;
	int x1,y1,r1,x2,y2,r2;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		if(x1==x2&&y1==y2)
		{
			if(r1==r2)
				printf("-1\n");
			else
				printf("0\n");
			continue;
		}
		int d =	(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		int ans=2;
		if(d>(r1-r2)*(r1-r2)&&d<(r1+r2)*(r1+r2))
		{
			ans=2;
		}
		else if(d==(r1-r2)*(r1-r2)||d==(r1+r2)*(r1+r2))
			ans=1;
		else if(d>(r1+r2)*(r1+r2)||d<(r1-r2)*(r1-r2))
			ans=0;
		printf("%d\n", ans);
	}
	return 0;
}
