#include<stdio.h>
#include<queue>
using namespace std;
int F,G,S,U,D;
bool visit[1000001];
int chk[1000001];
queue<int> q;
int main()
{
	int tmp;
	int next;
	int cnt=0;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	q.push(S);
	visit[S]=1;
	while(!q.empty())
	{
		tmp = q.front();
		//printf("tmp : %d\n",tmp);
		q.pop();
		next = tmp+U;
		if(next<=F&&visit[next]==0)
		{
			visit[next]=1;
			chk[next]=chk[tmp]+1;
			q.push(next);
		}
		next = tmp-D;
		if(next>=1&&visit[next]==0)
		{
			visit[next]=1;
			q.push(next);
			chk[next]=chk[tmp]+1;
		}
	}
	if(visit[G])
		printf("%d\n", chk[G]);
	else
		printf("use the stairs");

	return 0;
}
