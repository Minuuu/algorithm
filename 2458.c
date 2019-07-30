#include<stdio.h>
#include<limits.h>
int arr[51][51];
int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			arr[i][j]=100000;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		arr[a][b]=1;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(arr[i][j]>arr[i][k]+arr[k][j])
					arr[i][j]=arr[i][k]+arr[k][j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int a=0,b=0;
	//	printf("%d: ",i);
		for(int j=1;j<=n;j++)
		{
			if(arr[i][j]!=100000)
			{
				a++;
			}
			if(arr[j][i]!=100000)
				b++;

		}
	//	printf("%d %d\n", a,b);
		if(a+b==n-1)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
