#include<stdio.h>
#include<string.h>
long long map[5][5];
long long tmp[5][5];
long long ans[5][5];
long long n,b;
void print(long long arr[5][5])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%lld ", arr[i][j]);
		printf("\n");
	}
	printf("0-------------\n");

}
void getMatrix(long long a[5][5], long long b[5][5])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int sum = 0;
	//		ans[i][j]=0;
			for(int k=0;k<n;k++)
				sum+= (a[i][k]*b[k][j])%1000;
			ans[i][j] = sum%1000;
		}
	}
}
void solve(long long idx)
{
	if(idx==1)
	{
	//	getMatrix(map,map);
		memcpy(ans,map,sizeof(map));
	//	print(ans);
		return ;
	}
	solve(idx/2);
	memcpy(tmp,ans,sizeof(ans));
	getMatrix(tmp,tmp);
	//print(ans);
	if(idx%2==1)
	{
		memcpy(tmp,ans,sizeof(tmp));
		getMatrix(tmp,map);	
	}
}
int main()
{
	scanf("%lld %lld", &n, &b);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lld", &map[i][j]);
		}
	}
	solve(b);
	/*
	getMatrix(map,map);
	memcpy(tmp,ans,sizeof(map));
	getMatrix(tmp,tmp);
	memcpy(tmp,ans,sizeof(map));
	getMatrix(tmp,map);
	for(int i=0;i<n;i++)
	{
	}
	*/
//	printf("answer: \n");		
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%lld ", ans[i][j]%1000);
		printf("\n");
	}

	return 0;
}
