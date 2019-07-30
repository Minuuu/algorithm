#include<stdio.h>
#include<vector>
using namespace std;
int r,c,k;
int map[101][101];
void print(int arr[101][101])
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}
int rowCalc(int row, int col)
{
	int num=1;
	int col_size=-1;
	for(int i=1;i<=row;i++)
	{
		vector<pair<int,int> > v;
		int chk[101]={0,};
		for(int j=1;j<=col;j++)
		{
			chk[map[i][j]]++;
		}
		for(int j=1;j<=100;j++)
		{
			if(chk[j]!=0)
				v.push_back(make_pair(chk[j],j));
		}
		sort(v.begin(),v.end());
		for(int j=1;j<=col;j++)
			map[i][j]=0;
		int idx=1;
		for(int j=0;j<v.size();j++)
		{
			map[i][idx++]=v[j].second;
			map[i][idx++]=v[j].first;
		}
		idx--;
		col_size=max(idx,col_size);
	}
	return col_size;
}
int colCalc(int row, int col)
{
	int row_size=-1;
	for(int i=1;i<=col;i++)
	{
		vector<pair<int,int> > v;
		int chk[101]={0,};
		for(int j=1;j<=row;j++)
		{
			chk[map[j][i]]++;
		}
		for(int j=1;j<=100;j++)
		{
			if(chk[j]!=0)
				v.push_back(make_pair(chk[j],j));
		}
		sort(v.begin(),v.end());
		for(int j=1;j<=row;j++)
			map[j][i]=0;
		int idx=1;
		for(int j=0;j<v.size();j++)
		{
			map[idx++][i]=v[j].second;
			map[idx++][i]=v[j].first;
		}
		idx--;
		row_size = max(idx,row_size);
	}
	return row_size;
}
int solve()
{
	int rs=3;
	int cs=3;
	int ans = 0;
	int time=0;
	if(map[r][c]==k)
	{
		return ans;
	}
	while(1)
	{
		if(map[r][c]==k)
		{
			ans = time;
			break;
		}
		if(time>100)
		{
			ans=-1;
			break;
		}
		if(rs>=cs)
			cs = rowCalc(rs,cs);
		else
			rs = colCalc(rs,cs);
//		print(map);
		time++;
//		if(time==7)
//			break;
	}
	return ans;
}
int main()
{
	scanf("%d %d %d", &r, &c, &k);
	int ans=-1;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			scanf("%d", &map[i][j]);
	
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
