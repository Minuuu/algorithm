#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
int digit[6][6];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int ans[6];
map<int,int> m;

void dfs(int a, int b, int cnt)
{
	if(cnt==6)
	{
		int sum = ans[5]+ans[4]*10+ans[3]*100+ans[2]*1000+ans[1]*10000+ans[0]*100000;
		if(m[sum]==0){
			m.insert(make_pair(sum,1));
		}
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int nx = a+dir[i][0];
		int ny = b+dir[i][1];
		if(nx>0&&nx<=5&&ny>0&&ny<=5)
		{
			ans[cnt]=digit[nx][ny];
			dfs(nx,ny,cnt+1);
		}
	}
}
int main()
{
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			scanf("%d", &digit[i][j]);
		}	
	}
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			ans[0]=digit[i][j];
			dfs(i,j,1);
		}
	}
	printf("%d\n", m.size());
	return 0;
}
