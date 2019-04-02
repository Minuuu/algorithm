#include<stdio.h>
int N;
int user[1000001];
int B,C;
long long solve()
{
	long long master=0;
	long long serve=0;

	for(int i=1;i<=N;i++)
	{
		user[i]-=B;
		master++;
		if(user[i]<=0){
			continue;
		}
		else{
	//		printf("user: %d\n", user[i]);
			if(user[i]%C==0)
				serve+=user[i]/C;
			else
				serve+=(user[i]/C)+1;
		}
	//	printf("master: %d, server: %d\n", master, serve);
	}
	return master+serve;
}
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%d", &user[i]);

	scanf("%d %d", &B, &C);
	printf("%lld", solve());
	return 0;
}
