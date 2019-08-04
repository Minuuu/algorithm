#include<stdio.h>
#include<vector>
using namespace std;
int map[11][11];
int visit[11][11];
typedef pair<int,int> pii;
vector<pii> v;
int ans=987654321;
int cnt=0;
void chkVisit(int x, int y, int d, int val)
{
	for(int i=x;i<x+d;i++)
	{
		for(int j=y;j<y+d;j++)
			visit[i][j]=val;
	}
}
int isFill(int x, int y, int d)
{
	int cnt=0;
	for(int i=x;i<x+d;i++)
	{
		if(i>10)
			break;
		for(int j=y;j<y+d;j++)
		{
			if(j>10)
				break;
			if(map[i][j]==1&&visit[i][j]==0)
				cnt++;
		}
	}
	if(cnt==d*d)
		return 1;
	return 0;
}
int isRange(int x, int y)
{
	if(isFill(x,y,2)==1)
	{
		if(isFill(x,y,3)==1)
		{
			if(isFill(x,y,4)==1)
			{
				if(isFill(x,y,5)==1)
					return 5;
				return 4;
			}
			return 3;
		}
		return 2;
	}
	return 1;
}
void solve(int idx, int one, int two, int three, int four, int five)
{
	int all = one+two+three+four+five;
	int total = one+two*4+three*9+four*16+five*25;
	int x = v[idx].first;
	int y = v[idx].second;
	if(all>ans)
	{
		return ;
	}
	if(total==cnt)
	{
		ans = min(ans,all);
		return ;
	}
	if(visit[x][y]==1)
	{
		solve(idx+1,one,two,three,four,five);
		return ;
	}
	int flag = isRange(x,y);
	switch(flag)
	{
		case 5:
			if(five+1<=5)
			{
				chkVisit(x,y,5,1);
				solve(idx+1,one,two,three,four,five+1);
				chkVisit(x,y,5,0);
			}
		case 4:
			if(four+1<=5)
			{
				chkVisit(x,y,4,1);
				solve(idx+1,one,two,three,four+1,five);
				chkVisit(x,y,4,0);
			}
		case 3:
			if(three+1<=5)
			{
				chkVisit(x,y,3,1);
				solve(idx+1,one,two,three+1,four,five);
				chkVisit(x,y,3,0);
			}
		case 2:
			if(two+1<=5)
			{
				chkVisit(x,y,2,1);
				solve(idx+1,one,two+1,three,four,five);
				chkVisit(x,y,2,0);
			}

		case 1:
			if(one+1<=5)
			{
				chkVisit(x,y,1,1);
				solve(idx+1,one+1,two,three,four,five);
				chkVisit(x,y,1,0);
			}
			break;
	}
}
int main()
{

	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j]==1){
				cnt++;
				v.push_back(make_pair(i,j));
			}
		}
	}
	if(v.size()!=0)
		solve(0,0,0,0,0,0);
	else
		ans=0;
	if(ans==987654321)
		ans=-1;
	printf("%d\n", ans);
	

	return 0;
}
