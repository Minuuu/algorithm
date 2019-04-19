#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--){
		string str;
	//	getline(cin,str);
		cin>>str;
		string ans="";
		stack<char> result,s;
		int pos=0;
		int size=0;
		char c;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='-')
			{
				if(!result.empty()){
					result.pop();
				}
			}
			else if(str[i]=='<')
			{
				if(!result.empty()){
					c=result.top();
					s.push(c);
					result.pop();
				}
			}
			else if(str[i]=='>')
			{
				if(!s.empty()){
					c = s.top();
					result.push(c);
					s.pop();
				}
			}
			else{
				result.push(str[i]);
			}
			//	cout<<ans<<" pos: "<<pos<<" size: "<<size<<endl;
		}
		while(!s.empty())
		{
			c = s.top();
			s.pop();
			result.push(c);
		}
		while(!result.empty())
		{
			ans+=result.top();
			result.pop();
		}
		reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
	}
	return 0;
}
