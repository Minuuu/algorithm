#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int T,N,M,R,C,L;
int map[50][50];
typedef struct node{
	int x,y;
} Node;
int visit[50][50];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void print()
{
	printf("####\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			cout<<visit[i][j];
		cout<<endl;
	}
}
int ans=0;
void solve()
{
	int cnt=0;
	queue<Node> q;
	q.push({R,C});
	visit[R][C]=1;
	while(1)
	{
		cnt++;
		if(cnt==L)
		{
			cnt=0;
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<M;j++){
					if(visit[i][j]!=0)
						cnt++;
				}
			}
			ans=cnt;
	//		print();
			break;
		}
		int size = q.size();
		for(int j=0;j<size;j++){
			int x = q.front().x;
			int y = q.front().y;
			int num = map[x][y];
			//	printf("%d %d\n", x,y);
			q.pop();
			for(int i=0;i<4;i++)
			{
		//		if (num == 2 && (i == 0 || i == 2)) continue;
		//		else if (num == 3 && (i == 3 || i == 1)) continue;
		//		else if (num == 4 && (i == 1 || i == 2))continue;
		//		else if (num == 5 && (i == 3 || i == 2))continue;
		//		else if (num == 6 && (i == 3 || i == 0))continue;
		//		else if (num == 7 && (i == 0 || i == 1)) continue;
				int nx = x+dir[i][0];
				int ny = y+dir[i][1];
				if(nx>=0 && nx<N && ny>=0 && ny<M && visit[nx][ny]==0 && map[nx][ny]!=0)
				{
					if(i==0&&(num==1||num==3||num==4||num==5))
					{
						if(map[nx][ny]==1||map[nx][ny]==3||map[nx][ny]==6||map[nx][ny]==7){
							visit[nx][ny]=1;
							q.push({nx,ny});
						}
					}
					if(i==1&&(num==1||num==2||num==5||num==6))
					{
						if(map[nx][ny]==1||map[nx][ny]==2||map[nx][ny]==4||map[nx][ny]==7){
							visit[nx][ny]=1;
							q.push({nx,ny});
						}
					}
					if(i==2&&(num==1||num==3||num==6||num==7))
					{
						if(map[nx][ny]==1||map[nx][ny]==3||map[nx][ny]==4||map[nx][ny]==5){
							visit[nx][ny]=1;
							q.push({nx,ny});
						}
					}
					if(i==3&&(num==1||num==2||num==4||num==7))
					{
						if(map[nx][ny]==1||map[nx][ny]==2||map[nx][ny]==5||map[nx][ny]==6){
							visit[nx][ny]=1;
							q.push({nx,ny});
						}
					}
				}
			}
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>N>>M>>R>>C>>L;
//		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		ans=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				cin>>map[i][j];
				visit[i][j]=0;
			}
		}
		solve();
		cout<<"#"<<t<<" "<<ans<<endl;
	}
	return 0;
}
