#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char c;
	int ans=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %c", &c);
		ans+=c-'0';
	}
	printf("%d\n", ans);
	return 0;
}
