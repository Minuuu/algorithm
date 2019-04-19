#include<iostream>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M;
int map[101][101];
int visit[101];
void floyd()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=N;k++)
			{
				if(j!=k)
				map[j][k]=min(map[j][i]+map[i][k],map[j][k]);
				/*
				if(j==k)
					continue;
				if(map[j][i]&&map[i][k]){
					if(map[j][k]==0)
						map[j][k]=map[j][i]+map[i][k];
					else
						map[j][k]=min(map[j][i]+map[i][k],map[j][k]);
				}
				*/
			}
		}
	}
}
int main()
{
	cin>>N>>M;
	int x,y;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(i!=j)
				map[i][j]=1000000;
	for(int i=0;i<M;i++)
	{
		cin>>x>>y;
		map[x][y]=1;
		map[y][x]=1;
	}
	floyd();
	int num=INT_MAX;
	int ans=-1;
	for(int i=1;i<=N;i++)
	{
		int sum=0;
		for(int j=1;j<=N;j++)
			sum+=map[i][j];
		if(sum<num)
		{
			num=sum;
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
