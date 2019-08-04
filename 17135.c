#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
int N,M,D;
int map[16][16];
int temp[16][16];
int dir[3][2]={{0,-1},{-1,0},{0,1}};
typedef struct node{
	int x, y, dist;
} Node;
vector<int> v;
int solve()
{
	int a[16][16]={0,};
	for(int i=0;i<M;i++)
	{
		if(v[i]==1)
		{
			queue<struct node> q;
			int visit[16][16]={0,};
			Node n = {N-1,i,1};
			q.push(n);
			while(!q.empty())
			{
				int x = q.front().x;
				int y = q.front().y;
				int dist = q.front().dist;
				q.pop();
				if(map[x][y]==1&&dist<=D){
			//		printf("i: %d, %d %d\n", i, x,y);
					a[x][y]=1;
					break;
				}
				for(int j=0;j<3;j++)
				{
					int nx = x+dir[j][0];
					int ny = y+dir[j][1];
					if(nx>=0&&nx<=N-1&&ny>=0&&ny<=M-1)
					{
						if(visit[nx][ny]==0){
							if(dist+1<=D){
								Node tmp = {nx,ny,dist+1};
								q.push(tmp);
								visit[nx][ny]=1;
							}
						}
					}
				}
			}
		}
	}
	int ret=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(a[i][j]==1){
				ret++;
				map[i][j]=0;
			}
		}
	}
	return ret;
}
int check()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(map[i][j])
				return 1;
		}
	}
	return 0;
}
void print(int arr[16][16]);
void move()
{
	for(int i=0;i<M;i++)
	{
		for(int j=N-1;j>=1;j--)
		{
			map[j][i]=map[j-1][i];
		}
		map[0][i]=0;
	}
}
void print(int arr[16][16])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}
void copymap(int arr1[16][16], int arr2[16][16])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			arr2[i][j]=arr1[i][j];
	}
}
int main()
{	
	scanf("%d %d %d", &N, &M, &D);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d", &map[i][j]);
//	printf("\n");
	int ans=-1;
	for(int i=0;i<3;i++)
		v.push_back(1);
	for(int i=0;i<M-3;i++)
		v.push_back(0);
	memcpy(temp,map,sizeof(map));
	do{
		copymap(temp,map);
		int cnt=0;
		while(1){
			/*
			print(map);
			for(int i=0;i<v.size();i++)
				printf("%d ", v[i]);
			printf("\n");
			printf("-------\n");
			*/
			int num =solve();
		//	printf("%d\n", num);
			cnt+=num;
			move();
			int flag =check();
			if(flag!=1)
				break;
		}
		//printf("cnt: %d\n", cnt);
		if(ans<cnt)
			ans=cnt;
	}while(prev_permutation(v.begin(),v.end()));
	printf("%d\n", ans);
	return 0;
}
