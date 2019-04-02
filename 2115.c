#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int map[11][11];
int visit[11][11];
int T,N,M,C;
void print(int*);
int mb=-1;
void Max(int x, int y,int a, int sum, int pow)
{
    if(sum>C){
        return;
    }
    mb=max(mb,pow);
	if(a==M)
		return ;
    Max(x,y+1,a+1,sum+map[x][y],pow+map[x][y]*map[x][y]);
    Max(x,y+1,a+1,sum,pow);
}

int solve(int idx, int tmp)
{
	for(int i=0;i<M;i++)
		visit[idx][tmp+i]=1;
	mb=-1;
	Max(idx,tmp,0,0,0);
	int pA = mb;
	int pB = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-M+1; j++) {
            if (!visit[i][j]) {
                mb = -1;
                Max(i, j, 0, 0, 0);
                pB = max(pB, mb);
            }
        }
    }
	return pA+pB;
	
}
void print(int *arr)
{
	for(int i=0;i<M;i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d %d %d", &N, &M, &C);
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		int ans= -1 ;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N-M+1;j++)
			{
				ans=max(ans,solve(i,j));
			}
		}
		printf("#%d %d\n", t,ans);
	}
	return 0;
}
