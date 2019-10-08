#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n;
int map[101][101];
int visit[101][101];
int dir[2][2]={{0,1},{1,0}};
#define ppp  pair<pair<int,int>, pair<int,int>>
#define pii  pair<int,int>
struct node{
	int x, y, d;
};
int solution(vector<vector<int>> board)
{
	queue<node> q;
	q.push({1,2,0});
	int cnt = 0;
	int N = board.size();
	while(!q.empty())
	{
		int size = q.size();
		cnt++;
		printf("cnt: %d\n", cnt);
		for(int i=0;i<size;i++)
		{
			int x = q.front().x;
			int y = q.front().y;
			int d = q.front().d;
			printf("%d %d %d\n", x,y,d);
			q.pop();
			if(x==N && y==N){
				printf("!!\n");
				return cnt;
			}

			if(d==0)
			{
				int bx = x;
				int by = y-1;
		//		printf("%d %d\n", board[x+1][y], board[x+1][by]);
				if(x+1<=N&&board[x+1][y]==0&&board[x+1][by]==0)
				{
					q.push({x+1,y,d});
					q.push({x+1,y,1});
					q.push({x+1,by,1});
				}
				if(y+1<=N&&board[x][y+1]==0)
				{
					q.push({x,y+1,d});
				}
			}
			else if(d==1)
			{
				int bx = x-1;
				int by = y;
				if(x+1<=N && board[x][y]==0)
				{
					q.push({x+1,y,d});
				}
				if(y+1<=N&&board[x][y+1]==0 && board[bx][y+1]==0)
				{
					q.push({x,y+1,d});
					q.push({bx+1,y+1,0});
					q.push({bx,y+1,0});
				}
			}
		}
	}

	return -1;
}
int main()
{
	scanf("%d", &n);
	vector<vector<int>> v;
	vector<int> t;
	for(int i=0;i<=n;i++)
		t.push_back(0);
	v.push_back(t);
	for(int i=1;i<=n;i++)
	{
		vector<int> tmp;
		tmp.push_back(0);
		for(int j=1;j<=n;j++)
		{
			int num;
			scanf("%d", &num);
			tmp.push_back(num);
		}
		v.push_back(tmp);
	}
	for(int i=1;i<=n;i++)
	{
		vector<int> tmp = v[i];
		for(int j=1;j<=n;j++)
			printf("%d ", tmp[j]);
		printf("\n");
	}
	printf("%d\n", solution(v));
	return 0;
}
