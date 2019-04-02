#include<stdio.h>
using namespace std;

int N,M;
int map[26][26];
int visit[26][26];
int ddir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int sx, sy;
char pipe[8]={'|','-','+','1','2','3','4'};
int checkDir(int x, int y, int dir)
{
	int ndir=-1;
	switch(map[x][y])
	{
		case '|':
			if(dir==2||dir==3)
				ndir=dir;
			break;
		case '-':
			if(dir==0||dir==1)
				ndir=dir;
			break;
		case '1':
			if(dir==1)
				ndir=2;
			if(dir==3)
				ndir=0;
			break;
		case '2':
			if(dir==2)
				ndir=0;
			if(dir==1)
				ndir=3;
			break;
		case '3':
			if(dir==0)
				ndir=3;
			if(dir==2)
				ndir=1;
			break;
		case '4':
			if(dir==0)
				ndir=2;
			if(dir==3)
				ndir=1;
			break;
	}
	return ndir;
}
bool isBound(int x, int y)
{
	if(x>=1&&x<=N&&y>=1&&y<=M)
		return true;
	return false;
}
int next(int &x, int &y, int dir)
{
	switch(dir)
	{
		case 0:
			y+=1;
			break;
		case 1:
			y-=1;
			break;
		case 2:
			x+=1;
			break;
		case 3:
			x-=1;
			break;
	}
}
char find(int x, int y, int dir)
{
	int ndir=-1;
	int flag=0;
	int nx,ny;
	for(int i=0;i<7;i++)
	{
		map[x][y]=pipe[i];
		printf("f: %d %d %d %c\n", x,y,dir,map[x][y]);
		if(dir==0){
			if(map[x][y]=='-'||map[x][y]=='3'||map[x][y]=='4')
			{
				ndir=checkDir(x,y,dir);
	//			printf("%d %c\n", ndir,map[x][y]);
				nx=x;
				ny=y;
				next(nx,ny,ndir);
	//			printf("%d %d\n", nx,ny);
	//			printf("##find: %d %d %d %c\n", nx,ny,ndir,map[nx][ny]);
				if(map[nx][ny]!='.'){
					if(map[nx][ny]=='+')
						ndir=0;
					else
					ndir = checkDir(nx,ny,ndir);
	//				printf("ndir: %d %c\n", ndir, map[nx][ny]);
					if(ndir!=-1)
						return map[x][y];
				}
			}
			else if(map[x][y]=='+')
			{
				for(int j=0;j<4;j++)
				{
					nx = x+ddir[j][0];
					ny = y+ddir[j][1];
					
					if(isBound(x,y))
					{
						if(map[nx][ny]=='.')
							flag=1;
					}
					else{
						flag=1;
						break;
					}
				}
				if(!flag)
					return map[x][y];
			}
		}
		else if(dir==1){
			if(map[x][y]=='1'||map[x][y]=='2'||map[x][y]=='-'){
				ndir = checkDir(x,y,dir);
				nx=x;
				ny=y;
				next(nx,ny,ndir);
				if(map[nx][ny]!='.'){
					if(map[nx][ny]=='+')
						ndir=0;
					else
					ndir=checkDir(nx,ny,ndir);
					if(ndir!=-1)
						return map[x][y];
				}
			}
			else if(map[x][y]=='+')
			{
				for(int j=0;j<4;j++)
				{
					nx = x+ddir[j][0];
					ny = y+ddir[j][1];
					if(!isBound(nx,ny)){
						flag=1;
						break;
					}
					if(isBound(x,y))
					{
						if(map[nx][ny]=='.')
							flag=1;
					}
				}
				if(!flag)
					return map[x][y];
			}

		}
		else if(dir==2){
			if(map[x][y]=='2'||map[x][y]=='3'||map[x][y]=='|'){
				ndir = checkDir(x,y,dir);
				nx=x;
				ny=y;
				next(nx,ny,ndir);
				 if(map[nx][ny]!='.'){
					if(map[nx][ny]=='+')
					{
						ndir=0;
					}
					else{
                    ndir=checkDir(nx,ny,ndir);
//					printf("ndir: %d %c\n", ndir, map[nx][ny]);
					}
                    if(ndir!=-1)
                        return map[x][y];
                }

			}
			else if(map[x][y]=='+')
			{
				for(int j=0;j<4;j++)
				{
					nx = x+ddir[j][0];
					ny = y+ddir[j][1];
					if(isBound(nx,ny))
					{
						if(map[nx][ny]=='.')
							flag=1;
					}
					else{
						flag=1;
						break;
					}
				}
				if(!flag)
					return map[x][y];
			}

		}
		else if(dir==3){
			if(map[x][y]=='1'||map[x][y]=='4'||map[x][y]=='|'){
				ndir = checkDir(x,y,dir);
				nx=x;
				ny=y;
				next(nx,ny,ndir);
				 if(map[nx][ny]!='.'){
					if(map[nx][ny]=='+')
						ndir=0;
					else
                    ndir=checkDir(nx,ny,ndir);
                    if(ndir!=-1)
                        return map[x][y];
                }
			}
			else if(map[x][y]=='+')
			{
				for(int j=0;j<4;j++)
				{
					nx = x+ddir[j][0];
					ny = y+ddir[j][1];
					if(isBound(nx,ny))
					{
						if(map[nx][ny]=='.')
							flag=1;
					}
					else{
						flag=1;
						break;
					}
				}
				if(!flag)
					return map[x][y];
			}

		}
	}
}
//0: -> 1:<-
//2:|  3: ^
//	v	  |
void bfs(int x, int y, int dir)
{

	//printf("%d %d %c\n", x,y,map[x][y]);
	if(map[x][y]=='+'){
//		map[x][y]=0;
		for(int j=0;j<4;j++)
		{
			int nx = x+ddir[j][0];
			int ny = y+ddir[j][1];
			int ndir = j;
			if(map[nx][ny]=='.')
			{
				char str= find(nx,ny,ndir);
				printf("%d %d %c\n", nx,ny,str);
			}
			else{
				if(visit[nx][ny]==0){
					visit[nx][ny]=1;
					bfs(nx,ny,ndir);
				}
			}
		}
	}
	else{
		dir = checkDir(x,y,dir);
		next(x,y,dir);
		if(map[x][y]=='.')
		{
			char str = find(x,y,dir);
			printf("%d %d %c\n", x,y,str);
		}
		else{
			visit[x][y]=1;
			bfs(x,y,dir);
		}
	}
	return ;
}
int main()
{
	scanf("%d %d", &N, &M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf(" %c", &map[i][j]);
			if(map[i][j]=='M')
			{
				sx=i;
				sy=j;
			}
		}
	}

	for(int i=0;i<4;i++)
	{
		int x = sx+ddir[i][0];
		int y = sy+ddir[i][1];
		if(isBound(x,y))
			if(map[x][y]!='.'&&map[x][y]!='Z')
			{
				visit[x][y]=1;
				printf("%d %d\n", x,y);
				bfs(x,y,i);
			}
	}

	return 0;
}
