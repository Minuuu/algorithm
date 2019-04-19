#include<iostream>
using namespace std;
int visit[1001];
int N,M,L;
int main()
{
	cin>>N>>M>>L;
	int num=1;
	int cnt=0;
	visit[num]=1;
	while(1)
	{
		if(visit[num]==M)
			break;
		cnt++;
		if(visit[num]%2!=0)
			num=(num+L)%(N);
		else{
			num=(num+N-L)%(N);
		}
	//	cout<<num<<endl;
		visit[num]++;
	}
	cout<<cnt;
	return 0;
}
