#include<stdio.h>
#include<queue>
using namespace std;
int M,N;
int map[1001][1001];
//bool visit[1001][1001];
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
queue<pair<int,int>> q;
int cnt=0;
int neg=0;
int bfs()
{
	int size, x,y, nx, ny;
	while(!q.empty())
	{
		size = q.size();
		cnt++;
		for(int i=0;i<size;i++)
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();
//			visit[x][y]=1;
			for(int j=0;j<4;j++)
			{
				nx = x+dir[j][0];
				ny = y+dir[j][1];
				//printf("%d, %d %d\n", nx,ny,visit[nx][ny]);
				if(nx>0 && nx<=N && ny>0 && ny<=M &&map[nx][ny]==0)
				{
				//		printf("ok\n");
					if(map[nx][ny]!=-1){
						map[nx][ny]=1;			
						q.push(pair<int,int>(nx,ny));
					}
				}
			}
		}
	}
	return cnt-1;
}
int main()
{
	scanf("%d %d", &M, &N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++){
			scanf("%d", &map[i][j]);
			if(map[i][j]==-1)
				neg++;
		}
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(map[i][j]==1)
			{
				q.push(pair<int,int>(i,j));
			}
		}
	}
	int res;
	res = bfs();
	 int sum=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            sum+=map[i][j];
        }
    }
//  printf("%d, %d\n", sum,neg);
    if(sum==N*M||sum+neg*2==N*M)
        printf("%d", res);
    else{
        printf("-1");
    }

	return 0;
}
