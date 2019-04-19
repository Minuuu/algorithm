#include<iostream>
using namespace std;
int M,N;
int cnt=0;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int map[101][101];
bool visit[101][101];
void solve(int x, int y, int d)
{
	visit[x][y]=true;
	int nx = x+dir[d][0];
	int ny = y+dir[d][1];
	if(nx<=0||nx>M||ny<=0||ny>N||visit[nx][ny])
	{
		cnt++;
		d=(d+1)%4;
		nx=x+dir[d][0];
		ny=y+dir[d][1];
	}
	if(visit[nx][ny]==0)
		solve(nx,ny,d);
	
}
int main()
{
	cin>>M>>N;
	solve(1,1,0);
	cout<<cnt-1<<endl;
	return 0;
}
