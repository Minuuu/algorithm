#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int num;
		string str;
		cin>>num>>str;
		for(int i=0;i<str.length();i++)
		{
			for(int j=0;j<num;j++)
			{
				cout<<str[i];
			}
		}
		cout<<endl;
	}
	return 0;
}
