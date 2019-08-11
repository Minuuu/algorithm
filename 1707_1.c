#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int V,E;
int visit[20001];
int bfs(int num, vector<int> v[20001])
{
	queue<int> q;
	q.push(num);
	visit[num]=1;
	while(!q.empty())
	{
		num = q.front();
		q.pop();
		for(int i=0;i<v[num].size();i++)
		{
			if(visit[v[num][i]]==0)
			{
				if(visit[num]==1)
					visit[v[num][i]]=2;
				else if(visit[num]==2)
					visit[v[num][i]]=1;
				q.push(v[num][i]);
			}
			else
				if(visit[v[num][i]]==visit[num])
					return 0;
		}
	}
	return 1;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int ret = 0;
		scanf("%d %d", &V, &E);
		
		vector<int> v[20001];
		memset(visit,0,sizeof(visit));
		for(int i=0;i<E;i++)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=1;i<=V;i++)
		{
			if(visit[i]==0)
			{
				ret = bfs(i,v);
				if(ret==0)
					break;
			}
		}
		if(ret==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
