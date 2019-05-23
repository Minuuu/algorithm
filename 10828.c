#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int main()
{
	int n;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		if(str=="push")
		{
			int num;
			cin>>num;
			s.push(num);
		}
		else if(str=="top")
		{
			if(!s.empty())
				cout<<s.top()<<endl;
			else
				cout<<-1<<endl;
		}
		else if(str=="size")
		{
			cout<<s.size()<<endl;
		}
		else if(str=="empty")
		{
			cout<<s.empty()<<endl;
		}
		else if(str=="pop")
		{
			if(!s.empty()){
			cout<<s.top()<<endl;
			s.pop();
			}
			else
				cout<<-1<<endl;
		}
		

	}
	return 0;
}
