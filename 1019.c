#include<iostream>
#include<string.h>
using namespace std;
long long ans[10]={0,};
void calc(int n, int num)
{
	while(n>0){
		ans[n%10]+=num;
		n/=10;
	}
}
void solve(long long a, long long b, long long num)
{
	while(a%10!=0&&a<=b)
	{
		calc(a,num);
		a++;
	}
	if(a>b)
		return;
	while(b%10!=9&&a<=b)
	{
		calc(b,num);
		b--;
	}
	long long cnt = (b/10-a/10+1);
	for(int i=0;i<=9;i++)
		ans[i]+=cnt*num;
	solve(a/10,b/10,num*10);

}
int main()
{
	int num;
	cin>>num;
	solve(1,num,1);
	for(int i=0;i<10;i++)
		cout<<ans[i]<<' ';
	return 0;
}
