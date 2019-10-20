#include<stdio.h>
int N,M;
int visit[8] ;
void solve(int idx, int cnt)
{
	if(cnt==M){
		for(int i=0;i<N;i++)
			if(visit[i])
				printf("%d ", i+1);
		printf("\n");
		return ;
	}
	for(int i=0;i<N;i++){
		if(visit[i]==0){
			visit[i] = 1;
			solve(idx+1,cnt+1);
			visit[i] = 0;
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	solve(0,0);
	return 0;
}
