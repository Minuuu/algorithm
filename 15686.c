#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<vector>
using namespace std;
int N,M;
int map[51][51];
int visit[13];
int d;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int ans=INT_MAX;
vector<pair<int,int>> home;
vector<pair<int,int>> store;
void solve(int idx, int cnt)
{
	if(cnt==M)
	{
		int sum=0;
		for(int j=0;j<home.size();j++){
			int cd = INT_MAX;
			int hx = home[j].first;
			int hy = home[j].second;
			for(int i=0;i<store.size();i++)
			{
				if(visit[i]==1)
				{
					int x = store[i].first;
					int y = store[i].second;
					int tmp = abs(hx-x)+abs(hy-y);
					if(tmp<cd)
					{
						cd=tmp;
					}
				}
			}
			sum+=cd;
		}
		if(sum<ans)
			ans=sum;
		return ;
	}
	if(idx>=store.size())
		return ;
	visit[idx]=1;
	solve(idx+1,cnt+1);
	visit[idx]=0;
	solve(idx+1,cnt);
	return ;
}
int main()
{
	scanf("%d %d", &N, &M);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d", &map[i][j]);
			if(map[i][j]==1)
				home.push_back(make_pair(i,j));
			if(map[i][j]==2)
				store.push_back(make_pair(i,j));
		}
	}
	solve(0,0);
	printf("%d\n", ans);

	return 0;
}
