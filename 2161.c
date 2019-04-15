#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int N;
	cin>>N;
	queue<int> q;
	for(int i=1;i<=N;i++)
		q.push(i);
	
	int cnt=0;
	int num;
	while(!q.empty())
	{
		num=q.front();
		q.pop();
		if(cnt%2==0)
		{
			cout<<num<<" ";
		}
		else{
			q.push(num);
		}
		cnt++;
	}
	return 0;
}
