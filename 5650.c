#include<iostream>
#include<string.h>
#include<map>
using namespace std;
int T,N;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int sx,sy;
int ans=-1;
int table[101][101];
pair<int,int> m[10];
void solve(int x, int y, int d, int cnt)
{
	int score=cnt;
	if(sx==x&&sy==y){
		ans=max(ans,cnt);
		return ;
	}
	if(table[x][y]==-1){
		ans=max(ans,cnt);
		return ;
	}
	int tx, ty;
	if(table[x][y]>=6&&table[x][y]<=10)
	{
		if(m[table[x][y]-6].first==x&&m[table[x][y]-6].second == y){
			tx=m[table[x][y]-1].first;
			ty=m[table[x][y]-1].second;
		}
		else
		{
			tx=m[table[x][y]-6].first;
			ty=m[table[x][y]-6].second;
		}
		x=tx;
		y=ty;
	}
	switch(table[x][y])
	{
		case 1:
			if(d==0)
				d=2;
			else if(d==1)
				d=3;
			else if(d==2)
				d=1;
			else if(d==3)
				d=0;
			score+=1;
			break;
		case 2:
			if(d==0)
				d=1;
			else if(d==1)
				d=3;
			else if(d==2)
				d=0;
			else if(d==3)
				d=2;
			score+=1;
			break;
		case 3:
			if(d==0)
				d=3;
			else if(d==1)
				d=2;
			else if(d==2)
				d=0;
			else if(d==3)
				d=1;
			score+=1;
			break;
		case 4:
			if(d==0)
				d=2;
			else if(d==1)
				d=0;
			else if(d==2)
				d=3;
			else if(d==3)
				d=1;
			score+=1;
			break;
		case 5:
			if(d==0)
				d=2;
			else if(d==1)
				d=3;
			else if(d==2)
				d=0;
			else if(d==3)
				d=1;
			score+=1;
			break;
	}
	if(x+dir[d][0]<=0 || y+dir[d][1]<=0 || x+dir[d][0]>N || y+dir[d][1]>N)
	{
		d=(d+2)%4;
		score+=1;
		solve(x,y,d,score);
	}
	else
		solve(x+dir[d][0],y+dir[d][1],d,score);
	return ;
}
int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		ans=-1;
		cin>>N;
		memset(table,0,sizeof(table));
		memset(m,0,sizeof(m));
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				cin>>table[i][j];
				if(table[i][j]>=6&&table[i][j]<=10)
				{
					if(m[table[i][j]-6].first==0&&m[table[i][j]-6].second==0)
						m[table[i][j]-6]=make_pair(i,j);
					else{
						m[table[i][j]-1]=make_pair(i,j);
					}
				}
			}
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(table[i][j]==0)
				{
					sx=i;
					sy=j;
					for(int i=0;i<4;i++)
					{
						int nx = sx+dir[i][0];
						int ny = sy+dir[i][1];
						int d = i;
						if(nx>=1&&ny>=1&&nx<=N&&ny<=N){
							solve(nx,ny,d,0);
						}
					}
				}
			}
		}
		cout<<"#"<<t<<" "<<ans<<endl;
	}
	return 0;
}
