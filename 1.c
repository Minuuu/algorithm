#include<iostream>
using namespace std;
void solve(long long n)
{
	long long w=0,h=0;
	for(long long i=1;i*i<=n;i++)
        if(n%i==0){
            cout<<i<<' '<<n/i<<endl;
			h=i;
			w=n/i;
		}
	cout<<w-h;
}
int main()
{
	long long n;
	cin>>n;
	solve(n);

}
