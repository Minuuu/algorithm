#include<stdio.h>
int n;
char map[101][101];
int main()
{
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			scanf(" %c", &map[i][j]);
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(map[i][j]=='X')
			{
				if(cnt>=2)
					ans++;
				cnt=0;
			}
			else{
				cnt++;
			}
		}
		if(cnt>=2)
			ans++;
	}
	int ans2=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(map[j][i]=='X')
			{
				if(cnt>=2)
					ans2++;
				cnt=0;
			}
			else{
				cnt++;
			}
		}
		if(cnt>=2)
			ans2++;
	}
	printf("%d %d\n", ans,ans2);
	return 0;
}
