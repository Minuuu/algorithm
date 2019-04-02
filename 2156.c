#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
long long dp[10001];
long long grape[10001];
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%d", &grape[i]);

	dp[1]=grape[1];
	//dp[2]=grape[2];
	for(int i=2;i<=N;i++){
		dp[i]=max(max(dp[i-2]+grape[i],dp[i-3]+grape[i-1]+grape[i]),dp[i-1]);
	}
	printf("%ld\n", max(dp[N],dp[N-1]));
	return 0;
}
