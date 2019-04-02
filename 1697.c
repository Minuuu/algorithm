#include<stdio.h>
#include<queue>
using namespace std;
int N,K;
queue<int> q;
int visit[100001];
void bfs(int idx)
{
	int tmp;
	q.push(idx);
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		if(tmp==K)
			return ;
		if(tmp-1>=0&&visit[tmp-1]==0)
		{
			q.push(tmp-1);
			visit[tmp-1]=visit[tmp]+1;
		}
		if(tmp+1<100001&&visit[tmp+1]==0)
		{
			q.push(tmp+1);
			visit[tmp+1]=visit[tmp]+1;
		}
		if(tmp*2<100001&&visit[tmp*2]==0)
		{
			q.push(tmp*2);
			visit[tmp*2]=visit[tmp]+1;
		}
	}
}
int main()
{
	scanf("%d %d", &N, &K);
	bfs(N);
	printf("%d", visit[K]);
	return 0;
}
