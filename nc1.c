#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str="12345";
	string ans = str.find('4',2);//str.substr(2);
	cout<<ans;
	return 0;
}
