#include<iostream>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	cout<<str<<endl;;
	int cnt=0;
	for(int i=1;i<=str.length();i++)
	{
		if((str[i]==' '||str[i]=='\0')&&str[i-1]!=' ')
		{
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
