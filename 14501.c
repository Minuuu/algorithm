#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int N;
int dp[3][16];
int fdp(int idx)
{
	//printf("idx: %d\n", idx);
	if(idx==N+1){
	//	printf("fin\n");
		return 0;
	}
	if(idx>N+1)
		return -1234566;
	if(dp[0][idx]>0)
		return dp[0][idx];
	int val1 = fdp(idx+1);
	int val2 = fdp(idx+dp[1][idx])+dp[2][idx];
	dp[0][idx]=max(val1,val2);
//	dp[0][idx]= val1+ val2;
//	dp[0][idx]=max(fdp(idx+1),fdp(idx+dp[1][idx])+dp[2][idx]);
//	printf("%d, (%d,%d), %d\n", idx, val1, val2, dp[0][idx]);
	return dp[0][idx];
}
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%d %d", &dp[1][i], &dp[2][i]);
	
	int val=0;
	int MAX = -12;
	MAX=fdp(1);
	printf("%d", MAX);
	return 0;
}
