#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int M,N;
int map[50][50];
int cpm[8][8];
int ans=INT_MAX;
int solve()
{
	int res=0;
	int cnt1=0;
	int cnt2=0;
	//from 0
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if((i+j)%2==0)
			{
				if(cpm[i][j]!=0)
					cnt1++;
			}
			else{
				if(cpm[i][j]==0)
					cnt1++;
			}
		}
	}
	//from 1
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if((i+j)%2==0)
			{
				if(cpm[i][j]==0)
					cnt2++;
			}
			else{
				if(cpm[i][j]!=0)
					cnt2++;
			}
		}
	}
	return min(cnt1,cnt2);
}
void copyMap(int x, int y)
{
	for(int i=x;i<x+8;i++)
	{
		for(int j=y;j<y+8;j++)
			cpm[i-x][j-y]=map[i][j];
	}
}
int main()
{
	cin>>N>>M;
	char num;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin>>num;
			if(num=='W'){
				map[i][j]=0;
			}
			if(num=='B')
				map[i][j]=1;
		}
	}
	

	for(int i=0;i<N-7;i++)
	{
		for(int j=0;j<M-7;j++)
		{
			memset(cpm,0,sizeof(cpm));
			copyMap(i,j);
			ans =min(ans, solve());
		}
	}
	cout<<ans;
	return 0;
}
