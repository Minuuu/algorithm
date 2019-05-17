#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int visit[20001];
int V,E;
int bfs(vector<int> v[20001],int num)
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
			int tmp = v[num][i];
			if(visit[tmp]==0)
			{
				if(visit[num]==1)
					visit[tmp]=2;
				else if(visit[num]==2)
					visit[tmp]=1;
				q.push(tmp);
			}
			else{
				if(visit[tmp]==visit[num])
					return 0;
			}
		}
	}
	return 1;
}
int ans;
int cnt=0;
void dfs(vector<int> v[20001],int num, int color)
{
	visit[num]=color;
	cnt++;
	if(cnt==V)
		return ;
	for(int i=0;i<v[num].size();i++)
	{
		int tmp = v[num][i];
		if(visit[tmp]==0)
		{
			dfs(v,tmp,3-color);
		}
		if(visit[tmp]==color){
			ans=1;
			return ;
		}
	}
}
int main()
{
	int K;
	cin>>K;
	while(K--)
	{
		cin>>V>>E;
		vector<int> v[20001];
		memset(visit,0,sizeof(visit));
		ans=0;
		for(int i=0;i<E;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int ret=-1;
		for(int i=1;i<=V;i++)
		{
			if(visit[i]==0)
			{
				//ret = bfs(v,i);
				dfs(v,i,1);
				if(ans==1)
					break;
			}
		}
		if(ans==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
