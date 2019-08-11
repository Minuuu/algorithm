#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	while(n--)
	{
		string str;
		cin>>str;
		string origin = str;
		reverse(str.begin(),str.end());
		int num1 = stoi(origin);
		int num2 = stoi(str);
		string sum = to_string(num1+num2);
		int flag=0;
		for(int i=0;i<sum.length()/2;i++)
		{
			if(sum[i]!=sum[sum.length()-1-i])
			{
				flag=1;
				break;
			}
		}
		if(flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}

	return 0;
}
