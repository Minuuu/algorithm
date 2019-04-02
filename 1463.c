#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
int arr[1000001];
int solve(int n)
{
	if(n==1)
		return arr[n];
	if(arr[n]!=0)
		return arr[n];
	arr[n]=solve(n-1)+1;
	if(n%3==0)
	{
		int tmp = solve(n/3)+1;
		arr[n]=min(arr[n],tmp);
	}
	if(n%2==0)
	{
		int tmp = solve(n/2)+1;
		arr[n]=min(arr[n],tmp);
	}
	return arr[n];
}
int main()
{
	scanf("%d", &N);
	solve(N);
	printf("%d", arr[N]);
	return 0;
}
