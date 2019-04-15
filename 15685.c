#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef struct{
	int x,y,d,g;
} Node;
vector<Node> v;
int map[101][101];
int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
int getSquare()
{
	int ret=0;
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			if(map[i][j]&&map[i+1][j]&&map[i][j+1]&&map[i+1][j+1])
				ret++;
		}
	}
	return ret;
}
int main()
{
	int N,x,y,d,g;
	cin<<N;
	for(int i=0;i<N;i++)
	{
		cin>>x>>y>>d>>g;
		v.push_back({x,y,d,g});
		map[y][x]=1;
	}
	for(int i=0;i<v.size();i++)
	{
		int r = v[i].y;
		int c = v[i].x;
		int d = v[i].d;
		int g = v[i].g;
		int nx=r;
		int ny=c;
		vector<int> pos;
		pos.push_back(d);
		for(int j=0;j<g;j++)
		{
			for(int k=pos.size()-1;k>=0;k--)
			{
				int num = pos[k];
				pos.push_back((num+1)%4);
			}
		}
		for(int j=0;j<pos.size();j++)
		{
			nx+=dir[pos[j]][0];
			ny+=dir[pos[j]][1];
			map[nx][ny]=1;
		}
	}
	cout<<getSquare();
	return 0;
}
