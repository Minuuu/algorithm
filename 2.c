#include<iostream>
#include<vector>
using namespace std;
vector<string> v;
vector<string> nv;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		string tmp="";
		tmp+=s[i];
		if(s[i]>='A'&&s[i]<='Z')
		{
			if(s[i+1]>='a'&&s[i+1]<='z')
			{
				tmp+=s[i+1];
				i++;
			}
			v.push_back(tmp);
		}	
		if(s[i]=='1')
		{
			if(s[i+1]=='0')
		   	{
				tmp+=s[i+1];
				i++;
			}
			nv.push_back(tmp);
		}
		if(s[i]>='2'&&s[i]<='9')
			nv.push_back(tmp);
	}
	if(v.size()!=nv.size())
		cout<<"error";
	else{
		for(int i=0;i<v.size();i++)
		{
			cout<<v[i];
			if(nv[i]!="1")
				cout<<nv[i];
		}
	}
}


