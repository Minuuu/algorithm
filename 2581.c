#include<iostream>
using namespace std;
int arr[10001];
int main()
{
	int m,n;
	cin>>m>>n;
	arr[1]=1;
	for(int i=2;i*i<=n;i++)
	{
		if(arr[i]==0)
		{
			for(int j=i*2;j<=n;j+=i)
				arr[j]=1;
		}
	}
	int idx=10005;
	int sum=0;
	for(int i=m;i<=n;i++)
	{
		if(arr[i]==0)
		{
			if(i<idx)
				idx=i;
			sum+=i;
		}
	}
	if(idx==10005)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum,idx);
	return 0;
}
