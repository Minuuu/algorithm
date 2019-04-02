#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<vector>
#include<math.h>
using namespace std;
int T,N, K;
char digit[29];
map<int,int> m;
vector<int> v;
void print()
{
	for(int i=1;i<=N;i++)
		printf("%c ",digit[i]);
	cout<<endl;
}
void turn()
{
	digit[0]=digit[N];
	for(int i=N;i>=1;i--)
		digit[i]=digit[i-1];
}
int cal(string s)
{

	return 0;
}
void solve()
{
	int num=N/4;
	for(int i=0;i<4;i++)
	{
		int sum=0;
		string str="";
		for(int j=1;j<=num;j++)
		{
			if(digit[j+i*num]-55<10){
				sum+=(digit[j+i*num]-48)*pow(16,num-j);
			}
			else{
				sum+=(digit[j+i*num]-55)*pow(16,num-j);
			}
			//str+=digit[j+i*num];
		}
//		cout<<str<<endl;
//		printf("sum: %d\n", sum);
//		return ;
		if(m[sum]==0){
			m[sum]=1;
			v.push_back(sum);
		}
	}
}
int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(digit,0,sizeof(digit));
		cin>>N>>K;
		for(int i=1;i<=N;i++)
			scanf(" %1c", &digit[i]);
	//	print();
		for(int i=1;i<=N/4;i++)
		{
			solve();
			turn();
	//		print();
		}
		sort(v.begin(),v.end(),greater<int>());
		printf("#%d %d\n", t,v[K-1]);
		v.clear();
		m.clear();
	}
	return 0;
}
