#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int C,B;
int visit[650][200000];
int solve(int t, int b)
{
	int& ret = visit[t][b];
	if(ret!=0){
		return ret;
	}
	int c = C+(t*(t+1))/2;

	if(c>200000){
		ret=1;
		return -1;
	}
	if(b<0||b>200000){
		ret=1;
		//d[t][b]=-1;
		return -1;
	}

	if(c==b){
		//d[t][b]=t;
		ret=t;
		return ret;
	}
	int r1,r2,r3;
	r1=solve(t+1,b-1);
	r2=solve(t+1,b+1);
	r3=solve(t+1,2*b);
	ret = min(r1,min(r2,r3));
	//d[t][b] = min(r1,min(r2,r3));
	return ret;
}
int main()
{
	cin>>C>>B;
	if(C==B){
		cout<<0;
		return 0;
	}

	int a,b,c;
	memset(visit,0,sizeof(visit));
	a=solve(1,B-1);
//	cout<<a<<endl;
	printf("%d\n", a);
	b=solve(1,B+1);
//	cout<<b<<endl;
	printf("%d\n", b);

	c=solve(1,2*B);
//	cout<<c<<endl;
	printf("%d\n", c);

	int ans = min(a,min(b,c));
	cout<<ans;
	return 0;
}
