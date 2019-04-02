#include<stdio.h>
#include<string.h>
int T, N;
int map[21][21];
int visit[21];
int min=20001123;
int ans=0;
void solve(int idx, int cnt)
{
	if(idx>N)
		return;
	if(cnt>N/2)
		return ;
	if(cnt==N/2)
	{
		int A=0;
		int B=0;
		for(int i=1;i<=N;i++)
		{
			if(visit[i]==1)
			{
				for(int j=1;j<=N;j++)
				{
					if(visit[j]==1)
					{
						A+=map[i][j];
					}
				}
			}
			else
			{
				for(int j=1;j<=N;j++)
				{
					if(visit[j]==0)
					{
						B+=map[i][j];
					}
				}
			}
		}
		ans=A-B;
		if(ans<0)
			ans*=-1;
		if(min>ans)
			min=ans;
		return ;
	}
	visit[idx]=1;
	solve(idx+1,cnt+1);
	visit[idx]=0;
	solve(idx+1,cnt);
}
int main()
{
		scanf("%d", &N);
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
				scanf("%d", &map[i][j]);
		}
		solve(1,0);
		printf("%d\n",min);
	return 0;
}
