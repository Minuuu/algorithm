#include<stdio.h>
#include<queue>
using namespace std;
int N,A,D;
int map[101][101];
int visit[101][101];
int res=0;
int dir=1;//
queue<pair<int,char>> tmp;
queue<pair<int,int>> q;
int changeDir(char c){
	int d= dir;
	if(c=='L')
	{
		switch(d)
		{
			case 1:
				d=4;
				break;
			case 2:
				d=1;
				break;
			case 3:
				d=2;
				break;
			case 4:
				d=3;
				break;
		}
	}
	else if(c=='D')
	{
		switch(d)
		{
			case 1:
				d=2;
				break;
			case 2:
				d=3;
				break;
			case 3:
				d=4;
				break;
			case 4:
				d=1;
				break;
		}
	}
	return d;
}
void solve(int nx, int ny,int lvl)
{
	//printf("%d %d %d %d\n", q.front().first,q.front().second,nx,ny);
	if(nx<=0||ny<=0||nx>N||ny>N||visit[nx][ny]==1)
	{
		res=lvl;
		return ;
	}
	q.push(make_pair(nx,ny));

	if(map[nx][ny]==1){
		map[nx][ny]=0;
		visit[nx][ny]=1;
		int a = q.front().first;
		int b = q.front().second;
		visit[a][b]=1;
	}
	else{
		visit[nx][ny]=1;
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		visit[a][b]=0;
	}
	if(lvl==tmp.front().first){
		int c = tmp.front().second;
		tmp.pop();
		dir=changeDir(c);
	}
	switch(dir)
	{
		case 1:
			ny+=1;
			break;
		case 2:
			nx+=1;
			break;
		case 3:
			ny-=1;
			break;
		case 4:
			nx-=1;
			break;
	}
	solve(nx,ny,lvl+1);
}
int main()
{
	scanf("%d", &N);
	scanf("%d", &A);
	int ax,ay;
	for(int i=1;i<=A;i++)
	{
		scanf("%d %d", &ax, &ay);
		map[ax][ay]=1;
	}
	scanf("%d", &D);
	int n;
	char c;
	for(int i=1;i<=D;i++){
		scanf("%d %c", &n, &c);
		tmp.push(make_pair(n,c));
	}
	q.push(make_pair(1,1));
	solve(1,2,1);
	printf("%d\n", res);
	return 0;
}
