#include<iostream>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int cnt=0;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='c')
		{	
			if(str[i+1]=='=')
				i++;
			else if(str[i+1]=='-')
				i++;
		}
		else if(str[i]=='d')
		{
			if(str[i+1]=='z'&&str[i+2]=='=')
				i+=2;
			else if(str[i+1]=='-')
				i++;
		}
		else if(str[i]=='l')
		{
			if(str[i+1]=='j')
				i++;
		}
		else if(str[i]=='n')
		{
			if(str[i+1]=='j')
				i++;
		}
		else if(str[i]=='s')
		{
			if(str[i+1]=='=')
				i++;
		}
		else if(str[i]=='z')
		{
			if(str[i+1]=='=')
				i++;
		}
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;

}
