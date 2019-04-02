#include<stdio.h>
#include<cstdio>
#include<vector>
using namespace std;
int N,M;
int map[20][20];
int dir[5][2]={{0,0},{0,1},{0,-1},{-1,0},{1,0}};
int X,Y,K;
vector<int> v;
int dice[7];
int main()
{
	scanf("%d %d %d %d %d", &N, &M, &X, &Y, &K);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			scanf("%d", &map[i][j]);
	}
	int num;
	int nx=X;
	int ny=Y;
	for(int i=0;i<K;i++)
	{
		scanf("%d", &num);
		nx+=dir[num][0];
		ny+=dir[num][1];
		//printf("%d %d %d\n", nx, ny, dice[1]);
		if(nx<0||nx>=N||ny<0||ny>=M){
			nx-=dir[num][0];
			ny-=dir[num][1];
			continue;
		}
		switch(num)
		{
			case 1:
				swap(dice[1],dice[4]);
				swap(dice[2],dice[3]);
				break;
			case 2:
				swap(dice[1],dice[3]);
				swap(dice[2],dice[4]);
				break;
			case 3:
				swap(dice[1],dice[5]);
				swap(dice[2],dice[6]);
				break;
			case 4:
				swap(dice[1],dice[6]);
				swap(dice[2],dice[5]);
				break;
		}
		swap(dice[1],dice[2]);
		if(map[nx][ny]!=0){
			dice[2]=map[nx][ny];
			map[nx][ny]=0;
		}
		else{
			map[nx][ny]=dice[2];
		}
		/*
		for(int i=1;i<=6;i++)
			printf("%d ", dice[i]);
		printf("\n");
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
				printf("%d ", map[i][j]);
			printf("\n");
		}
		*/
		printf("%d\n", dice[1]);
	}
	return 0;
}
