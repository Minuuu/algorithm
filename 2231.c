#include<stdio.h>
#include<algorithm>
using namespace std;
int visit[1000001];
int main()
{
	int N;
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
	{
		int sum=i;
		int n=i;
		while(n!=0){
			sum+=(n%10);
			n/=10;
		}
		if(visit[sum]==0)
			visit[sum]=i;
		else
			visit[sum]=min(visit[sum],sum);
	}
	printf("%d", visit[N]);
	return 0;
}
