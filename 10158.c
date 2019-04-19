#include<iostream>
using namespace std;
int dir[4][2]={{1,1},{-1,1},{-1,-1},{1,-1}};
int main()
{
	int w,h,x,y,t;
	cin>>w>>h;
	cin>>x>>y;
	cin>>t;
	int dx=1,dy=1;
	int nx,ny;
	nx = (x+t)/w;
	ny = (y+t)/h;
	if(nx%2==0)
		x=(x+t)%w;
	else
		x=w-((x+t)%w);

	if(ny%2==0)
		y = (y+t)%h;
	else
		y=h-((y+t)%h);
	cout<<x<<' '<<y<<endl;
	//cout<<nx<<ny<<endl;
	return 0;
}
