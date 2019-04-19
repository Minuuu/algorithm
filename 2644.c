#include<iostream>
#include<queue>
using namespace std;
int map[101][101];
int visit[101];
int d[101];
int N,a,b,M,cnt=0;
void bfs(int num)
{
	queue<int> q;
	q.push(num);
	while(!q.empty())
	{
		int idx = q.front();
		q.pop();
		for(int i=1;i<=N;i++)
		{
			if(visit[i]==0&&map[idx][i]==1)
			{
				q.push(i);
				d[i]=d[idx]+1;
				visit[i]=1;
			}
		}
	}
}
int main()
{
	cin>>N;
	cin>>a>>b;
	cin>>M;
	int num1,num2;
	for(int i=0;i<M;i++)
	{
		cin>>num1>>num2;
		map[num1][num2]=1;
		map[num2][num1]=1;
	}
	bfs(a);
	if(d[b]==0)
		d[b]=-1;
	cout<<d[b]<<endl;
	return 0;
}
