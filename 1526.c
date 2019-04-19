#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	int num;
	int ans=0;
	queue<int> q;
	cin>>num;
	if(num>=4)
	{
		ans=4;
		q.push(4);
	}
	if(num>=7)
	{
		ans=7;
		q.push(7);
	}
	while(!q.empty())
	{
		int tmp = q.front();
		q.pop();
		tmp*=10;
		if(tmp+4<=num){
			ans=tmp+4;
			q.push(ans);
		}
		if(tmp+7<=num){
			ans=tmp+7;
			q.push(ans);
		}
	}
	cout<<ans;

	return 0;
}
