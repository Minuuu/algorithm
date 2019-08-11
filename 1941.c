#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	char input[25][25];
    char map[26];
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf(" %c", &input[i][j]);
	for(int i=0;i<25;i++)
		map[i] = input[i/5][i%5];
	vector<int> v;
	for(int i=0;i<7;i++)
		v.push_back(1);
	for(int i=0;i<18;i++)
		v.push_back(0);
	int ans=0;
	do{
		vector<pair<int,int>> tmp;
		int sCnt=0;
		int cnt=0;
		for(int i=0;i<25;i++)
		{
			if(v[i]==1)
			{
				int r = i/5;
				int c = i%5;
				tmp.push_back({r,c});
				if(map[i]=='S')
					sCnt++;
			}
		}
		if(sCnt>=4){
			queue<pair<int,int>> q;
            bool visit[7]={0,};
            int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};

			q.push({tmp[0].first,tmp[0].second});
			while(!q.empty())
			{
				int x = q.front().first;
				int y =q.front().second;
				q.pop();
				for(int i=0;i<4;i++)
				{
					int nx = x+dir[i][0];
					int ny = y+dir[i][1];
					for(int j=0;j<7;j++)
					{
						if(nx==tmp[j].first&&ny==tmp[j].second&&!visit[j])
						{
							visit[j]=1;
							q.push({nx,ny});
							cnt++;
						}
					}
				}
			}
            if(cnt>=7)
    			ans++;
		}
		
	}while(prev_permutation(v.begin(),v.end()));
	printf("%d\n", ans);
	return 0;
}

