#include<stdio.h>
int N,M;
int map[101][101];
int visit[101][101];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int dfs(int a, int b)
{
	visit[a][b]=1;
	for(int i=0;i<4;i++)
	{
		int nx = a+dir[i][0];
		int ny = b+dir[i][1];
	//	printf("%d %d\n", nx,ny);
		if(nx<=0||nx>N||ny<=0||ny>M)
			continue;
		if(map[nx][ny]==0){
			map[nx][ny]=-1;
			dfs(nx,ny);
		}
		else if(map[nx][ny]>=1){
			map[nx][ny]++;
		}
	}
	return -1;
}
int main()
{
	scanf("%d %d", &N, &M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
			scanf("%d", &map[i][j]);
	}
	/*
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
			dfs(i,j);
	}
	*/
	int cnt=0;
	int sum=0;
	while(1){
		cnt++;
		int res = dfs(1,1);
		sum=0;

		if(res==-1)
		{
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=M;j++)
				{
					if(map[i][j]==-1)
						map[i][j]=0;
					else if(map[i][j]>=3)
						map[i][j]=0;
					else if(map[i][j]>=1)
						map[i][j]=1;
					sum+=map[i][j];
				//	printf("%2d ", map[i][j]);
				}
//				printf("\n");
			}
		//	printf("%d\n", sum);
			if(sum==0)
				break;
//			break;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
