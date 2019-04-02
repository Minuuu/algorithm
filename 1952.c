#include<stdio.h>
int T;
int plan[12];
int price[4];
int ans=1000000000;
int dp[13];
int min(int a, int b)
{
	if(a<b)
		return a;
	return b;
}
void solve(int idx, int sum)
{
	if(idx>=12){
		if(ans>sum)
			ans=sum;
		return ;
	}
	if(plan[idx]==0){
		solve(idx+1,sum);
		return ;
	}
	solve(idx+1,sum+price[0]*plan[idx]);
	solve(idx+1,sum+price[1]);
	solve(idx+3,sum+price[2]);
}
int main()
{
	scanf("%d", &T);
	for(int t=1;t<=T;t++){
		ans=1000000000;
		for(int i=0;i<4;i++)
			scanf("%d", &price[i]);
		for(int i=0;i<12;i++)
			scanf("%d", &plan[i]);
/*
		solve(0,0);
		if(ans>price[3])
			ans=price[3];
			*/
		for(int i=1;i<=12;i++)
		{
			dp[i]=dp[i-1]+min(price[0]*plan[i-1],price[1]);
			if(i-3>=0){
				int tmp=dp[i-3]+price[2];
				dp[i]=min(dp[i],tmp);
			}
		}
		dp[12]=min(dp[12],price[3]);
		printf("#%d %d\n", t, dp[12]);
	}

	return 0;
}
