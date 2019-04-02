#include<stdio.h>
int N;
int visit[10001];
void solve(int n)
{
	int x=1;
	int idx=0;
	int sum=n;
	while(n>=x){
		idx++;
		x*=10;
	}
	x/=10;
	//printf("%d %d\n", idx, x);
	for(int i=0;i<idx;i++)
	{
		sum+=n/x;
		n=n%x;
		x/=10;
	}
	visit[sum]+=1;
}
int main()
{
	for(int i=1;i<=10000;i++)
		solve(i);
	for(int i=1;i<=10000;i++)
	{
		if(visit[i]==0)
			printf("%d\n",i);
	}
	return 0;
}
