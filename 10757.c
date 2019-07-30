#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<int> v;
string A,B;
int main()
{
	cin>>A>>B;
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	int lenA = A.length();
	int lenB = B.length();
	if(lenA>lenB)
	{
		swap(lenA,lenB);
		swap(A,B);
	}
	int flag=0;
	for(int i=0;i<lenA;i++)
	{
		int a = A[i]-'0';
		int b = B[i]-'0';
		int sum = a+b+flag;
		if(sum>=10)
			flag=1;
		else
			flag=0;
		v.push_back(sum%10);
	}
	for(int i=lenA;i<lenB;i++)
	{
		int b = B[i]-'0';
		int sum = b+flag;
		if(sum>=10)
			flag=1;
		else
			flag=0;
		v.push_back(sum%10);
	}
	if(flag)
		v.push_back(flag);
	for(int i=v.size()-1;i>=0;i--)
		printf("%d",v[i]);

	/*
	for(int i=lenB-1;i>=lenA;i--)
	{
		int b = B[i]-'0';
		v.push_back((flag+b)%10);
	}
	*/
	}
	return 0;
}
