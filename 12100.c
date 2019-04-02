#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
int N;
int map[21][21];
void print(int (*p)[21])
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			printf("%d", p[i][j]);
		printf("\n");
	}
}
int dfs(int dir, int cnt, int (*mapp)[21])
{
	if(cnt==5)
	{
		int max=-1;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(max<mapp[i][j]){
					max=mapp[i][j];
				}
			}
		}
		return max;
	}
	int copy[21][21];
	memcpy(copy, mapp, sizeof(copy));
	vector<int> v;
	print(copy);
	switch(dir)
	{
		case 1:
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=N;j++)
				{
					v.push_back(copy[j][i]);
				}
				for(int j=0;j<v.size()-1;j++)
				{
					if(v[j]==v[j+1])
					{
						v[j]*=2;
						v[j+1]=0;
					}
				}
				for(int j=0;j<v.size();j++)
					printf("%d", v[j]);
				printf("\n");
				for(vector<int>::iterator iter=v.begin();iter!=v.end();iter++)
				{
					if(*iter==0)
						v.erase(iter);
				}
				printf("%d\n", v.size());
				int tmp=0;
				printf("!\n");
				for(int j=1;j<=N;j++){
					if(tmp>=v.size())
						copy[j][i]=0;
					else
						copy[j][i]=v[tmp++];
				}
				printf("!\n");
				v.clear();
			}
			printf("cnt: %d, dir: %d\n", cnt,dir);
			print(copy);
			break;
		case 2:
			for(int i=1;i<=N;i++)
			{
				for(int j=N;j>=1;j--)
				{
					v.push_back(copy[i][j]);
				}
				for(int j=0;j<v.size()-1;j++)
				{
					if(v[j]==v[j+1])
					{
						v[j]*=2;
						v[j+1]=0;
					}
				}
				for(vector<int>::iterator iter=v.begin();iter!=v.end();iter++)
				{
					if(*iter==0)
						v.erase(iter);	
				}
				int tmp=0;
				for(int j=N;j>=1;j--)
				{
					if(tmp>=v.size())
						copy[i][j]=0;
					else
						copy[i][j]=v[tmp++];
				}
				v.clear();
			}
			print(copy);
			break;
		case 3:
			printf("cnt: %d, dir: %d\n", cnt,dir);
			for(int i=1;i<=N;i++)
			{
				for(int j=N;j>=1;j--)
					v.push_back(copy[j][i]);
				for(int j=0;j<v.size()-1;j++)
				{
					if(v[j]==v[j+1])
					{
						v[j]*=2;
						v[j+1]=0;
					}
				}
				for(vector<int>::iterator iter=v.begin();iter!=v.end();iter++)
				{
					if(*iter==0)
						v.erase(iter);
				}
				int tmp=0;
				for(int j=N;j>=1;j--)
				{
					if(tmp>=v.size())
						copy[j][i]=0;
					else
						copy[j][i]=v[tmp++];
				}
			v.clear();
			}
			printf("cnt: %d, dir: %d\n", cnt,dir);
			print(copy);
			break;
		case 4:
			for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j--)
                {
                    v.push_back(copy[i][j]);
                }
                for(int j=0;j<v.size()-1;j++)
                {
                    if(v[j]==v[j+1])
                    {
                        v[j]*=2;
                        v[j+1]=0;
                    }
                }
                for(vector<int>::iterator iter=v.begin();iter!=v.end();iter++)
                {
                    if(*iter==0)
                        v.erase(iter);
                }
                int tmp=0;
                for(int j=1;j<=N;j--)
                {
                    if(tmp>=v.size())
                        copy[i][j]=0;
                    else
                        copy[i][j]=v[tmp++];
                }
                v.clear();
            }
			printf("cnt: %d, dir: %d\n", cnt,dir);
			print(copy);
			break;
	}
	int res=0;
	for(int i=1;i<=4;i++)
	{
		printf("okn\n");
		if(i==dir)
			continue;
		res=dfs(i,cnt+1,copy);
	}
	return res;
}
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			scanf("%d", &map[i][j]);
	}
	int max=-1;
	int res=0;
	for(int i=1;i<=4;i++)
	{
		res = dfs(2,1, map);
		if(max<res)
			max=res;
		break;
	}
	printf("%d\n", max);
	return 0;
}
