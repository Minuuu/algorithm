#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int N,K,M;
vector<vector<int>> station, tube;
//vector<int> visit;
int s_visit[100001];
int t_visit[100001];
queue<int> q;
int bfs()
{
	q.push(1);
	s_visit[1]=1;
	while(!q.empty())
	{
		int tmp = q.front();
		q.pop();
		if(tmp==N){
			return s_visit[tmp];
//			printf("%d\n", s_visit[tmp]);
//			return ;
		}
		
		for(int i=0;i<station[tmp].size();i++)
		{
			int t = station[tmp][i];
			if(t_visit[t]==0){	
				t_visit[t]=1;
				for(int j=0;j<tube[t].size();j++)
				{
					if(s_visit[tube[t][j]]==0)
					{
						s_visit[tube[t][j]]=s_visit[tmp]+1;
						q.push(tube[t][j]);
					}
				}
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d %d %d", &N, &K, &M);
	station = vector<vector<int>>(N+1);
	tube = vector<vector<int>>(M+1);
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=K;j++)
		{
			int num;
			scanf("%d", &num);
			tube[i].push_back(num);
			station[num].push_back(i);
		}
	}
	printf("%d", bfs());


	return 0;
}
