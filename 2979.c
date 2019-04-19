#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> v;
int dp[3][101];
int main()
{
	int A,B,C;
	cin>>A>>B>>C;
	int arr,dep;
	int maxT=0;
	for(int i=0;i<3;i++)
	{
		cin>>arr>>dep;
		maxT=max(maxT,dep);
		for(int j=arr;j<dep;j++)
			dp[i][j]=1;
	}
	int sum=0;
	for(int i=1;i<maxT;i++)
	{
		int cnt=0;
		for(int j=0;j<3;j++)
		{
			if(dp[j][i]==1)
				cnt++;
		}
		if(cnt==1)
			sum+=A;
		else if(cnt==2)
			sum+=B*2;
		else if(cnt==3)
			sum+=C*3;
	//	cout<<"t: "<<i<<"sum: "<<sum<<endl;
	}
	cout<<sum<<endl;

	return 0;
}
