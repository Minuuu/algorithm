#include<stdio.h>
#include<vector>
using namespace std;
int map[9][9];
int ans=0;
vector<pair<int,int>> v;
bool isPossible(int x, int y, int num)
{
	for(int i=0;i<9;i++)
	{
		if(map[i][y]==num||map[x][i]==num)
			return false;		
	}
	int sx = x/3*3;
	int sy = y/3*3;
	for(int i=sx;i<sx+3;i++)
	{
		for(int j=sy;j<sy+3;j++)
		{
			if(map[i][j]==num)
				return false;
		}
	}
	return true;
}
void solve(int idx)
{
	int x = v[idx].first;
	int y = v[idx].second;
	if(idx==v.size())
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
				printf("%d ", map[i][j]);
			printf("\n");
		}
		ans = 1;
		return ;
	}
	for(int i=1;i<=9;i++)
	{
		if(isPossible(x,y,i)&&ans==0)
		{
			map[x][y]=i;
			solve(idx+1);
			map[x][y]=0;
		}
	}

}
int main()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j]==0)
			{
				v.push_back({i,j});
			}
		}
	}

	solve(0);
}
