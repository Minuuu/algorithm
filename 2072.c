#include<stdio.h>
int main()
{
	int T;
	int arr[11];
	scanf("%d", &T);
	for(int i=1;i<=T;i++)
	{
		int ans=0;
		for(int j=1;j<=10;j++)
		{
			scanf("%d", &arr[j]);
			if(arr[j]%2==1)
				ans+=arr[j];
		}
		printf("#%d %d\n", i,ans);
		
	}
	return 0;
}
