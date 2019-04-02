#include<stdio.h>
int map[301][301];
int main()
{
	int N,M,K;
	scanf("%d %d", &N, &M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
			scanf("%d", &map[i][j]);
	}
	scanf("%d", &K);
	for(int i=1;i<=K;i++)
	{
		int sum=0,sx,sy,ex,ey;
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		for(int i=sx;i<=ex;i++){
			for(int j=sy;j<=ey;j++)
				sum+=map[i][j];
		}
		printf("%d\n", sum);
	}
}
