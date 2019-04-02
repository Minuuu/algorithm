#include<stdio.h>
#include<string.h>
int T,N;
int map[41][21];
int X;
int visit[41][21];
int road(int row, int idx, int num)
{
	int flag=0;
	if(num==1)
	{
		if(idx-X<1)
			return 0;
		for(int i=idx-X;i<idx-1;i++){
			if(visit[row][i]||map[row][i]!=map[row][i+1])
				flag=1;
		}
		if(flag)
			return 0;
		for(int i=idx-X;i<idx;i++)
			visit[row][i]=1;
		return 1;
	}
	else if(num==-1){
		if(idx+X-1>N)
			return 0;
		for(int i=idx+X-1;i>idx;i--)
		{
			if(visit[row][i]||map[row][i]!=map[row][i-1])
				flag=1;
		}
		if(flag)
			return 0;
		for(int i=idx+X-1;i>=idx;i--)
			visit[row][i]=1;
		return 1;
	}
	return 0;
}
int solve(int idx)
{
	for(int i=2;i<=N;i++)
	{
		if(map[idx][i]!=map[idx][i-1])
		{
			if(!road(idx,i,map[idx][i]-map[idx][i-1]))
				return 0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d", &T);
	for(int c=1;c<=T;c++)
	{
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		scanf("%d %d", &N, &X);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				scanf("%d", &map[i][j]);
		for(int i=N+1;i<=2*N;i++)
			for(int j=1;j<=N;j++)
				map[i][j]=map[j][i-N];

		int res=0;
		for(int i=1;i<=2*N;i++)
			res+=solve(i);
		printf("#%d %d\n", c,res);
	}
	return 0;
}
