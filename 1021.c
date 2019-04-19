#include<iostream>
#include<deque>
using namespace std;
int N,M;
int main()
{
	int num;
	cin>>N>>M;
	deque<int> q;
	for(int i=0;i<N;i++)
		q.push_back(i+1);
	int cnt=0;
	for(int i=0;i<M;i++)
	{
		cin>>num;
		int idx;
		for(int i=0;i<q.size();i++)
		{
			if(num==q[i])
			{
				idx=i;
				break;
			}
		}
		int l = idx;
		int r = q.size()-idx;
		if(l<r)
		{
			for(int i=1;i<=l;i++)
			{
				q.push_back(q[0]);
				q.pop_front();
				cnt++;
			}
			q.pop_front();
		}
		else{
			for(int i=1;i<=r;i++)
			{
				q.push_front(q[q.size()-1]);
				q.pop_back();
				cnt++;
			}
			q.pop_front();
		}
	}
	cout<<cnt<<endl;
	return 0;
}
