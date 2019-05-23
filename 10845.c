#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> q;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		if(str=="push")
		{
			int num;
			cin>>num;
			q.push_back(num);
		}
		else if(str=="front")
		{
			if(q.empty())
				cout<<"-1"<<endl;
			else
				cout<<q.front()<<endl;
		}
		else if(str=="back")
		{
			if(q.empty())
				cout<<"-1"<<endl;
			else
				cout<<q.back()<<endl;
		}
		else if(str=="size")
		{
			cout<<q.size()<<endl;
		}
		else if(str=="empty")
			cout<<q.empty()<<endl;
		else if(str=="pop")
		{
			if(q.empty())
				cout<<"-1"<<endl;
			else{
				cout<<q.front()<<endl;
				q.pop_front();
			}
		}
	}
	return 0;
}
