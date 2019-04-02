#include<stdio.h>
#include<queue>
using namespace std;
int N,M;
int map[11][11];
struct Node{
	int rx,ry,bx,by,cnt;
};
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
queue<struct Node> q;
bool visit[11][11][11][11];
int main()
{
	scanf("%d %d", &N, &M);
	struct Node n;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++){
			scanf(" %c", &map[i][j]);
			if(map[i][j]=='B'){
				n.bx=i; n.by=j;
			}
			else if(map[i][j]=='R')
			{
				n.rx=i;
			   	n.ry=j;
			}
		}
	}
	n.cnt=0;
	q.push(n);
	visit[n.rx][n.ry][n.bx][n.by]=1;
	int ans=-1;
	while(!q.empty())
	{
		int nrx = q.front().rx;
		int nry = q.front().ry;
		int nbx = q.front().bx;
		int nby = q.front().by;
		int ncnt = q.front().cnt;
		q.pop();
		if(ncnt>10)
			break;
		if(map[nrx][nry]=='O'){
			ans = ncnt;
			break;
		}

		for(int i=0;i<4;i++)
		{
			int rx = nrx+dir[i][0];
			int ry = nry+dir[i][1];
			int bx = nbx+dir[i][0];
			int by = nby+dir[i][1];
			
			while(1)
			{
				if(map[rx][ry]=='O')
				{
					//ans = ncnt;
					break;
				}
				if(map[rx][ry]=='#'){
					rx-=dir[i][0];
					ry-=dir[i][1];
					//printf("%d, %d\n", rx,ry);
					break;
				}
				rx = rx+dir[i][0];
				ry = ry+dir[i][1];
			}

			while(1)
			{
				if(map[bx][by]=='O'){
					//ans = -1;
					break;
				}
				if(map[bx][by]=='#'){
					bx-=dir[i][0];
					by-=dir[i][1];
					break;
				}
				bx = bx+dir[i][0];
				by = by+dir[i][1];
			}
			if(map[bx][by]=='O')
				continue;
			if(rx==bx&&ry==by)
			{
				switch(i)
				{
					case 0:
						if(nry<nby)
							ry--;
						else
							by--;
						break;
					case 1:
						if(nry<nby)
							by++;
						else
							ry++;
						break;
					case 2:
						if(nrx<nbx)
							rx--;
						else
							bx--;
						break;
					case 3:
						if(nrx<nbx)
							bx++;
						else
							rx++;
						break;
				}
			}
			if(!visit[rx][ry][bx][by]){
				q.push({rx,ry,bx,by,ncnt+1});
				visit[rx][ry][bx][by]=1;
			}
		}
	}
	printf("%d", ans);
	
	return 0;
}
