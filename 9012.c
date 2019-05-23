#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		stack<char> s;
		string str;
		cin>>str;
		string ans="YES";
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='(')
			{
				s.push(str[i]);
			}
			else if(str[i]==')')
			{
				if(s.empty())
				{
					ans="NO";
					break;
				}
				else{
					s.pop();
				}
			}
		}
		if(s.size()==0)
		{
			cout<<ans<<endl;
		}
		else
			cout<<"NO"<<endl;

	}
	return 0;
}
