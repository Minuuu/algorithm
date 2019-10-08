#include<iostream>
#include<vector>
using namespace std;
int map[101][101];
int arr[10][4]={{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1},};
int arr1[10][4]={{0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1}};
int visit[101][101];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int r, int c, int d,int flag, vector<vector<int>> &v,int n)
{	
	visit[r][c] = 1;
	printf("r: %d, c: %d d: %d flag: %d\n", r,c, d, flag);

	vector<int> tmp;
	/*
	if(flag ==0){
		tmp.push_back(c);
		tmp.push_back(r);
		tmp.push_back(d);
	}
	else{
		if(d==0)
		{
			tmp.push_back(c);
			tmp.push_back(r-1);
		}
		else
		{
			tmp.push_back(c-1);
			tmp.push_back(r);
		}
		tmp.push_back(d);
	}
	*/
	tmp.push_back(c);
	tmp.push_back(r);
	tmp.push_back(d);
	v.push_back(tmp);
			
	for(int i=0;i<4;i++)
	{
		int nr = r+dir[i][0];
		int nc = c+dir[i][1];
		if(nr>=0&&nr<=n&&nc>=0&&nc<=n)
		{
			if(map[nr][nc]==1&&!visit[nr][nc])
			{
				visit[nr][nc] = 1;
				if(i<2)
					dfs(nr,nc,i%2,0,v,n);
				else
					dfs(nr,nc,i%2,1,v,n);
			}
		}
	}
	return ;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
	vector<vector<int>> answer;
	for(int i=0;i<build_frame.size();i++)
	{
		vector<int> v = build_frame[i];
		int x = v[0];
		int y = v[1];
		int a = v[2];
		int b = v[3];
		if(b==1)
		{
			if(a==0)
				map[y+1][x] = 1;
			map[y][x] = 1;
		}
		else
			map[y][x] = 0;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(!visit[i][j]&&map[i][j]==1)
			{
				printf("call\n");
				dfs(i,j,0,0,answer,n);
				
				break;
			}
		}
	}
	printf("size: %d\n", answer.size());
	for(int i=0;i<answer.size();i++)
	{
		for(int j=0;j<3;j++)
			printf("%d ", answer[i][j]);
		printf("\n");
	}
	cout<<build_frame.size()<<endl;
	return answer;
}
int main()
{
	vector<vector<int>> v;
	for(int i=0;i<8;i++)
	{
		vector<int> tmp;
		for(int j=0;j<4;j++)
			tmp.push_back(arr1[i][j]);
		v.push_back(tmp);
	}
	solution(5,v);


	return 0;
}
