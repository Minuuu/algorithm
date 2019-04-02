#include<stdio.h>
int main()
{
	int arr[11];
	int T;
	scanf("%d", &T);
	for(int i=1;i<=T;i++)
	{
		int ans=0;
		for(int j=1;j<=10;j++)
		{
			scanf("%d", &arr[j]);
			ans+=arr[j];
		}
			if(ans%10>=5)
			{
				ans=ans/10;
				ans++;
			}
			else
				ans/=10;
		printf("#%d %d\n", i, ans);
	}
	return 0;
}
