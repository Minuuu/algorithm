#include<iostream>
#include<cstring>
char map[13][7];
bool visit[13][7];
using namespace std;
int cnt=0;
int dir[4][2]={{0,1},{-1,0},{1,0},{0,-1}};
bool solve(int x, int y, char c)
{
	cnt++;
	for(int i=0;i<4;i++)
	{
		int nx = x+dir[i][0];
		int ny = y+dir[i][1];
		if(nx>=1&&nx<=12&&ny>=1&&ny<=6&&!visit[nx][ny])
		{
			if(map[nx][ny]==c){
				visit[nx][ny]=true;
				solve(nx,ny,c);
			}
		}
	}
}
void print()
{
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=6;j++)
			cout<<map[i][j]<<' ';
		cout<<endl;
	}
}
void draw()
{
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=6;j++)
		{
			if(visit[i][j])
				map[i][j]='.';
		}
	}
}
void drop(){
	for(int i=1;i<=6;i++)
	{
		for(int j=11;j>=1;j--)
		{
			for(int k=12;k>j;k--){
				if(map[j][i]!='.'&&map[k][i]=='.')
				{
					map[k][i]=map[j][i];
					map[j][i]='.';
					break;
				}
			}
		}
	}
}
int main()
{
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=6;j++)
			cin>>map[i][j];
	}
	int ans=0;
	int tmp[13][7];
	while(1)
	{
		int flag=0;
		memset(visit,false,sizeof(visit));
		for(int i=1;i<=12;i++)
		{
			for(int j=1;j<=6;j++)
			{
				if(!visit[i][j]&&map[i][j]!='.'){
					cnt=0;
					memcpy(tmp,visit,sizeof(tmp));
					visit[i][j]=1;
					solve(i,j,map[i][j]);
					if(cnt>=4)
					{
						flag=1;
					}
					else
						memcpy(visit,tmp,sizeof(tmp));
				}
			}
		}
		if(flag==0)
			break;
		else
			ans++;
		draw();
		drop();
	}
	cout<<ans;
	return 0;
}
