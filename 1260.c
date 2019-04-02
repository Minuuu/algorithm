#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int map[1001][1001];
int visit[1001];
int N,M,S;
queue<int> q;
void dfs(int c) {
    if (visit[c] == 1) return;

    visit[c] = 1;
    printf("%d ", c); 
    
    for (int i = 1; i <= N; i++)
        if (map[c][i] == 1)
            dfs(i);
}
void bfs(int s)
{
	int i;
	q.push(s);
	visit[s]=1;
	while(!q.empty())
	{
		int tmp=q.front();
		printf("%d ", tmp);
		q.pop();
		for(i=1;i<=N;i++)
		{
			if(map[tmp][i]==1)
			{
				if(visit[i]==0){
					visit[i]=1;
					q.push(i);
				}
			}		
		}
	}
	return ;
}

int main()
{
	int i;
	int j,k;
	scanf("%d %d %d", &N,&M,&S);
	for(i=1;i<=M;i++)
	{
		scanf("%d %d", &j,&k);
		map[j][k]=1;
		map[k][j]=1;
	}
	dfs(S);
	printf("\n");
	memset(visit,0,sizeof(visit));
	bfs(S);
	return 0;
}
