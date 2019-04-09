#include<stdio.h>
#include<math.h>
#include<queue>
#include<limits.h>
using namespace std;
int N;
int map[21][21];
typedef struct {
	int x,y,dst,eat;
} Fish;
int bx,by;
vector<Fish> v;
int go()
{
	int x=INT_MAX,y=INT_MAX,idx=-1;
	int tmp=INT_MAX;
	for(int i=0;i<v.size();i++)
	{
		if(v[i].dst==0)
			continue;
		if(v[i].dst<tmp)
		{
			x=v[i].x;
			y=v[i].y;
			idx=i;
			tmp=v[i].dst;
		}
		else if(v[i].dst==tmp)
		{
			if(v[i].x<x)
			{
				x=v[i].x;
				y=v[i].y;
				idx=i;
				continue;
			}
			else if(v[i].x>x)
				continue;

			if(v[i].y<y)
			{
				x=v[i].x;
				y=v[i].y;
				idx=i;
				continue;
			}
		}
	}
	return idx;
}
void changeV()
{
	for(int i=0;i<v.size();i++)
		printf("%d %d %d\n", v[i].x, v[i].y,v[i].dst);
	printf("\n");
}
int chk=0;
int time=0;
bool find(int size)
{
	for(int i=0;i<v.size();i++)
	{

		if(map[v[i].x][v[i].y]<size){
			return true;
		}
	}
	return false;
}
void solve(int x, int y, int size, int cnt)
{
	int idx,fx,fy,fs;
	int a=0;
	printf("##solve: %d %d %d %d\n", x,y,size,cnt);
	printf("time: %d\n", time);
	if(v.size()==0){
		return;
	}
	for(int i=0;i<v.size();i++)
	{
		v[i].dst = abs(x-v[i].x)+abs(y-v[i].y);
	}
	while(1){
		if(!find(size))
		{
			return ;
		}
		idx = go();
		fx=v[idx].x;
		fy=v[idx].y;
		fs = map[fx][fy];
		if(size>=fs)
			break;
		else{
			v[idx].dst=INT_MAX;
		}
	}
	changeV();
	printf("idx: %d\n", idx);
	/*
	if(chk==3)
	{
		printf("time: %d\n", time);
		return ;
	}
	*/
	if(size==fs){
		time+=v[idx].dst;
		solve(fx,fy,size,cnt);
	}
	if(size>fs){
		cnt++;
		if(cnt==size)
		{
			printf("dst: %d\n", v[idx].dst);
			time+=v[idx].dst;
			v.erase(v.begin()+idx,v.begin()+idx+1);
			solve(fx,fy,size+1,0);
		}
		else{
			chk++;
			printf("dst: %d\n", v[idx].dst);
			time+=v[idx].dst;
			v.erase(v.begin()+idx,v.begin()+idx+1);
			solve(fx,fy,size,cnt);
		}
	}
}
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j]==9)
			{
				bx=i;
				by=j;
			}
		}
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(map[i][j]>=1&&map[i][j]<=6)
			{
				int size = abs(i-bx)+abs(j-by);
				v.push_back({i,j,size,0});
			}
		}
	}
	solve(bx,by,2,0);
	printf("%d\n", time);
	return 0;
}
