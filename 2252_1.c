#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
vector<int> v[32001];
priority_queue<int> pq;
int in[32001];
int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		in[b]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(in[i]==0)
			q.push(i);
	int cnt=0;
	while(!q.empty())
	{
		int num = q.front();
		in[num] = -1;
		q.pop();
		if(cnt==n)
			break;
		printf("%d ", num);
		for(int i=0;i<v[num].size();i++)
		{
			in[v[num][i]]--;
			if(in[v[num][i]]==0){
				q.push(v[num][i]);
			}
		}
	}
	return 0;
}