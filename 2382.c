#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int T;
int N,M,K;
int d[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};
typedef struct node{
	int x;
	int y;
	int cnt;
	int dir;
} Node;
int map[100][100];
Node bug[1000];
void mix(int x, int y)
{
	int maxBug=-1;
	int dir;
	int sum=0;
	int idx=-1;
	for(int i=0;i<K;i++)
	{
		if(bug[i].x==x&&bug[i].y==y)
		{
			sum+=bug[i].cnt;
			if(maxBug<bug[i].cnt)
			{
				if(idx!=-1)
				{
					bug[idx].x=0;
					bug[idx].y=0;
					bug[idx].cnt=0;
					bug[idx].dir=0;
				}
				idx = i;
				maxBug=bug[i].cnt;
				dir=bug[i].dir;
			}
			else{
				bug[i].x=0;
				bug[i].y=0;
				bug[i].cnt=0;
				bug[i].dir=0;
			}
		}
	}
	bug[idx].cnt=sum;
	bug[idx].dir=dir;
}
int main()
{
	scanf("%d", &T);
	for(int t=1;t<=T;t++)
	{
		memset(bug,0,sizeof(bug));
		memset(map,0,sizeof(bug));

		scanf("%d %d %d", &N, &M, &K);
		int x, y, cnt, dir;
		for(int i=0;i<K;i++){
			scanf("%d %d %d %d", &bug[i].x,&bug[i].y,&cnt,&dir);
			bug[i].cnt=cnt;
			bug[i].dir=dir;
			map[bug[i].x][bug[i].y]=1;
		}
		for(int m=0;m<M;m++){

			for(int i=0;i<K;i++)
			{
				int nx = bug[i].x+d[bug[i].dir][0];
				int ny = bug[i].y+d[bug[i].dir][1];
				map[bug[i].x][bug[i].y]--;
				bug[i].x=nx;
				bug[i].y=ny;
				map[nx][ny]++;
			}
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
				{
					if(map[i][j]>1)
					{
						mix(i,j);
						map[i][j]=1;
					}
				}
			}
			for(int i=0;i<K;i++)
			{
				if(bug[i].x==0||bug[i].x==N-1||bug[i].y==0||bug[i].y==N-1)
				{
					switch(bug[i].dir)
					{
						case 1:
							bug[i].dir=2;
							break;
						case 2:
							bug[i].dir=1;
							break;
						case 3:
							bug[i].dir=4;
							break;
						case 4:
							bug[i].dir=3;
							break;
					}
					bug[i].cnt/=2;
				}
			}
		}
		cnt=0;
		for(int i=0;i<K;i++)
			cnt+=bug[i].cnt;
		printf("#%d %d\n", t, cnt);
	}
	return 0;
}
