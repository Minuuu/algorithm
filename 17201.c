#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string str;
	cin>>str;
	int flag=0;
	for(int i=0;i<str.length();i+=2)
	{
		if(str[i]=='1'&&str[i+1]=='2')
			continue;
		else{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		for(int i=0;i<str.length();i+=2)
		{
			if(str[i]=='2'&&str[i+1]=='1')
				continue;
			else{
				flag=2;
				break;
			}
		}
	}
	if(flag==2)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}
