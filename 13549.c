#include<iostream>
#include<queue>
#include<climits>
using namespace std;
int visit[100001];
queue<pair<int,int>> q;
int N,K;
int ans=INT_MAX;
void solve(int n)
{
	q.push({n,0});
	visit[n]=1;
	while(!q.empty())
	{
		int pos = q.front().first;
		int time = q.front().second;
	//	cout<<pos<<' '<<time<<endl;
		q.pop();
		if(pos==K){
			ans=min(ans,time);
	//		printf("%d\n", ans);
			return ;
		}
		else{
			if(pos*2<100001 && visit[pos*2]==0)
			{
				q.push({pos*2,time});
				visit[pos*2]=time;
			}
			if(pos-1>=0 && visit[pos-1]==0)
			{
				q.push({pos-1,time+1});
				visit[pos-1]=time;
			}
			if(pos+1<100001 && visit[pos+1]==0)
			{
				q.push({pos+1,time+1});
				visit[pos+1]=time;
			}
		}
	}
}
int main()
{
	cin>>N>>K;
	solve(N);
	cout<<ans;
	return 0;
}
