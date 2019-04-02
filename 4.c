#include<iostream>
using namespace std;
int N;
int height[1000001];
int main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>height[i];
	int idx=1;
	int ans=1;
	for(int i=idx+1;i<=N;i++)
	{
		if(height[idx]<=height[i])
		{
			if(ans<i-idx)
			{
				ans=i-idx;
				idx=i;
			}
		}
		else
		{
			for(int j=i-1;j>=idx;j--)
			{
				if(height[j]>=height[i]){
					if(ans<i-idx)
						ans=i-j;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
