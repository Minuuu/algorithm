#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		while(1)
		{
			char c;
			scanf(" %c", &c);
			int I,J;
			if(c=='E')
			{
				scanf("%d", &I);
			}
			else if(c=='I')
			{
				scanf("%d %d", &I, &J);
			}
			else{
				break;
			}
		}
	}
	return 0;
}
