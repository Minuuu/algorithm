#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[21];
int n,s;
int ans=0;
void solve(int idx, int sum, int len)
{
	if(idx==n+1){
		if(sum==s&&len!=0)
		{
			ans++;
		}
		return ;
	}
	solve(idx+1,sum+arr[idx],len+1);
	solve(idx+1,sum,len);
}
int main()
{
	scanf("%d %d", &n, &s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &arr[i]);
	}
	solve(1,0,0);
	printf("%d", ans);
	return 0;
}
