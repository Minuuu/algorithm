#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
vector<char> v1,v2;
char str[50];
int visit[20];
int ans = -987654321;
int n;
int calc(char a, char b, char c)
{
	int num1 = a-'0';
	int num2 = b-'0';
	switch(c)
	{
		case '+':
			return num1+num2;
		case '-':
			return num1-num2;
		case '*':
			return num1*num2;
	}
	printf("???\n");
	return 987654321;
}
void solve(int idx)
{
	if(idx==n-1)
	{
		vector<string> v;
		vector<char> op;
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(visit[i]==1 && visit[i+2]==1)
			{
				flag=1;
				break;
			}
			if(visit[i]==1)
			{
				int sum = calc(str[i],str[i+2],str[i+1]);
				v.push_back(to_string(sum));
				i+=2;
			}
			else{
				string s = "";
				s+=str[i];
				v.push_back(s);
			}
		}
		if(flag==0){
			int sum = stoi(v[0]);
			for(int i=1;i<v.size();i++)
			{
				if(v[i]=="+")
				{
					sum += stoi(v[i+1]);
					i++;
				}
				else if(v[i]=="*")
				{
					sum *= stoi(v[i+1]);
					i++;
				}
				else if(v[i]=="-")
				{
					sum -= stoi(v[i+1]);
					i++;
				}
			}
			cout<<sum;
			cout<<endl;
			ans = max(sum,ans);

		}
	}
	if(idx>=n)
		return ;
	visit[idx]=1;
	solve(idx+2);
	visit[idx]=0;
	solve(idx+2);
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		char c;
		scanf(" %c", &str[i]);
	}
	solve(0);
	printf("%d\n", ans);
	return 0;
}
