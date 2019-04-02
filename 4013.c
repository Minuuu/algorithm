#include<stdio.h>
#include<string.h>
int T,K;
int map[5][9];
int visit[5];
void turn(int num, int dir)
{
	if(dir==1)
	{
		int tmp = map[num][8];
		for(int i=8;i>=2;i--)
			map[num][i]=map[num][i-1];
		map[num][1]=tmp;
	}
	else{
		int tmp = map[num][1];
		for(int i=1;i<=7;i++)
			map[num][i]=map[num][i+1];
		map[num][8]=tmp;
	}
}
void solve(int num, int dir)
{
	visit[num]=1;
	if(num<=0||num>=5)
		return ;
	if(num<=3&&map[num][3]!=map[num+1][7]&&visit[num+1]==0)
	{
		solve(num+1,dir*-1);
	}
	if(num>=1&&map[num][7]!=map[num-1][3]&&visit[num-1]==0)
	{
		solve(num-1,dir*-1);
	}
	turn(num,dir);
}
int main()
{
	scanf("%d", &T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d", &K);
		int num;
		int dir;//1 시계, -1 반시계
		for(int i=1;i<=4;i++)
			for(int j=1;j<=8;j++)
				scanf("%d", &map[i][j]);
		for(int i=0;i<K;i++){
			memset(visit,0,sizeof(visit));
			scanf("%d %d", &num, &dir);
			solve(num,dir);
			/*
			for(int j=1;j<=4;j++)
			{
				for(int k=1;k<=8;k++)
					printf("%d ", map[j][k]);
				printf("\n");
			}
			*/
		}
		int ans=0;
		if(map[1][1]==1)
			ans+=1;
		if(map[2][1]==1)
			ans+=2;
		if(map[3][1]==1)
			ans+=4;
		if(map[4][1]==1)
			ans+=8;
		printf("#%d %d\n", i, ans);
	}
	return 0;
}
