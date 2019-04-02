#include<iostream>
#include<queue>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
int T,N,W,H;
int ans=INT_MAX;
int map[16][13];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void copy(int (*a)[13], int (*b)[13])
{
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=W;j++)
			a[i][j]=b[i][j];
	}
	return ;
}
void boom(int x, int y)
{
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	while(!q.empty())
	{
		int qx = q.front().first;
		int qy = q.front().second;
		int block = map[qx][qy];
		q.pop();
		map[qx][qy]=0;
		for(int j=1;j<block;j++)
		{
			for(int i=0;i<4;i++)
			{
				int nx = qx+dir[i][0]*j;
				int ny = qy+dir[i][1]*j;
				if(nx>=1 && nx<=H && ny>=1 && ny<=W)
				{
					if(map[nx][ny]!=0){
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
	}
	return ;
}
void destroy()
{
	queue<int> q;
	for(int i=1;i<=W;i++)
	{
		for(int j=H;j>=1;j--)
		{
			if(map[j][i]!=0)
			{
				q.push(map[j][i]);
			}
			map[j][i]=0;
		}
		for(int j=H;q.size()!=0;j--)
		{
			map[j][i]=q.front();
			q.pop();
		}
	}
}

void solve(int n)
{
	int cp[16][13];
	memset(cp,0,sizeof(cp));
	copy(cp,map);
	if(n==N)
	{
		int cnt=0;
		for(int i=1;i<=H;i++)
		{
			for(int j=1;j<=W;j++){
				if(map[i][j]!=0)
					cnt++;
			}
		}
		if(ans>cnt)
			ans=cnt;
		return ;
	}
	for(int j=1;j<=W;j++)
	{
		for(int i=1;i<=H;i++)
		{
			if(cp[i][j]!=0)
			{
				boom(i,j);
				destroy();
				solve(n+1);
				copy(map,cp);
				break;
			}			
		}
	}
	
	return ;
}
int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>N>>W>>H;
		ans=INT_MAX;
		memset(map,0,sizeof(map));
		for(int i=1;i<=H;i++)
			for(int j=1;j<=W;j++)
				cin>>map[i][j];
		solve(0);
		if(ans==INT_MAX)
			ans=0;
		cout<<"#"<<t<<" "<<ans<<endl;
	}
	return 0;
}
