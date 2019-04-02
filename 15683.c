#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<vector>
using namespace std;
int N,M;
int map[9][9];
vector<pair<int,int>> v;
int ans=INT_MAX;
void solve(int idx,int cnt, int (*copy)[9])
{
	if(cnt==v.size())
	{
		int scnt=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
				if(copy[i][j]==0)
					scnt++;
		}
		if(ans>scnt)
			ans=scnt;
		return ;
	}
	int x = v[idx].first;
	int y = v[idx].second;
	int tmp[9][9];
	switch(map[x][y])
	{
		case 1:
			for(int i=1;i<=4;i++)
			{
				memcpy(tmp,copy,sizeof(tmp));
				switch(i)
				{
					case 1:
						for(int j=y+1;j<=M;j++)
						{
							if(tmp[x][j]==6)
								break;
							else if(tmp[x][j]==0)
								tmp[x][j]=7;
						}
						break;
					case 2:
						for(int j=x+1;j<=N;j++)
						{
							if(tmp[j][y]==6)
								break;
							else if(tmp[j][y]==0)
								tmp[j][y]=7;
						}

						break;
					case 3:
						for(int j=y-1;j>=1;j--)
						{
							if(tmp[x][j]==6)
								break;
							else if(tmp[x][j]==0)
								tmp[x][j]=7;
						}

						break;
					case 4:
						for(int j=x-1;j>=1;j--)
						{
							if(tmp[j][y]==6)
								break;
							else if(tmp[j][y]==0)
								tmp[j][y]=7;
						}

						break;
				}
				solve(idx+1,cnt+1,tmp);
			}
			break;
		case 2:
			for(int i=1;i<=2;i++)
            {
                memcpy(tmp,copy,sizeof(tmp));
				if(i==1){
					for(int j=y+1;j<=M;j++)
					{
						if(tmp[x][j]==6)
							break;
						else if(tmp[x][j]==0)
							tmp[x][j]=7;
					}
					for(int j=y-1;j>=1;j--)
					{
						if(tmp[x][j]==6)
							break;
						else if(tmp[x][j]==0)
							tmp[x][j]=7;
					}
				}
				else{
					for(int j=x+1;j<=N;j++)
					{
						if(tmp[j][y]==6)
							break;
						else if(tmp[j][y]==0)
							tmp[j][y]=7;
					}

					for(int j=x-1;j>=1;j--)
					{
						if(tmp[j][y]==6)
							break;
						else if(tmp[j][y]==0)
							tmp[j][y]=7;
					}
				}
                solve(idx+1,cnt+1,tmp);
            }
			
			break;
		case 3:
			for(int i=1;i<=4;i++)
            {
                memcpy(tmp,copy,sizeof(tmp));
				if(i<=2){
					for(int j=y+1;j<=M;j++)
					{
						if(tmp[x][j]==6)
							break;
						else if(tmp[x][j]==0)
							tmp[x][j]=7;
					}
				}
				if(i==2||i==3){
					for(int j=x+1;j<=N;j++)
					{
						if(tmp[j][y]==6)
							break;
						else if(tmp[j][y]==0)
							tmp[j][y]=7;
					}
				}
				if(i>=3){
					for(int j=y-1;j>=1;j--)
					{
						if(tmp[x][j]==6)
							break;
						else if(tmp[x][j]==0)
							tmp[x][j]=7;
					}
				}
				if(i==4||i==1){
					for(int j=x-1;j>=1;j--)
					{
						if(tmp[j][y]==6)
							break;
						else if(tmp[j][y]==0)
							tmp[j][y]=7;
					}
				}
                solve(idx+1,cnt+1,tmp);
            }

			break;
		case 4:
			for(int i=1;i<=4;i++)
            {
                memcpy(tmp,copy,sizeof(tmp));
				if(i!=4)
				{
					for(int j=y+1;j<=M;j++)
					{
						if(tmp[x][j]==6)
							break;
						else if(tmp[x][j]==0)
							tmp[x][j]=7;
					}
				}
				if(i!=2)
				{
					for(int j=y-1;j>=1;j--)
					{
						if(tmp[x][j]==6)
							break;
						else if(tmp[x][j]==0)
							tmp[x][j]=7;
					}
				}
				if(i!=1)
				{
					for(int j=x+1;j<=N;j++)
					{
						if(tmp[j][y]==6)
							break;
						else if(tmp[j][y]==0)
							tmp[j][y]=7;
					}
				}
				if(i!=3){
					for(int j=x-1;j>=1;j--)
					{
						if(tmp[j][y]==6)
							break;
						else if(tmp[j][y]==0)
							tmp[j][y]=7;
					}
				}
                solve(idx+1,cnt+1,tmp);
            }
			break; 
		case 5:
            memcpy(tmp,copy,sizeof(tmp));
			for(int i=x+1;i<=N;i++)
			{
				if(tmp[i][y]==6)
					break;
				else if(tmp[i][y]==0)
					tmp[i][y]=7;
			}
			for(int i=x-1;i>=1;i--)
			{
				if(tmp[i][y]==6)
					break;
				else if(tmp[i][y]==0)
					tmp[i][y]=7;
			}
			for(int i=y+1;i<=M;i++)
			{
				if(tmp[x][i]==6)
					break;
				else if(tmp[x][i]==0)
					tmp[x][i]=7;
			}
			for(int i=y-1;i>=1;i--)
			{
				if(tmp[x][i]==6)
					break;
				else if(tmp[x][i]==0)
					tmp[x][i]=7;
			}
			solve(idx+1,cnt+1,tmp);
			break;
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	int copy[9][9]={0,};
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j]>=1&&map[i][j]<=5)
				v.push_back(make_pair(i,j));
		}
	}
	memcpy(copy,map,sizeof(map));
	solve(0,0,copy);
	printf("%d\n", ans);
	return 0;
}
