#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
int T,N;
int map[11][11];
typedef struct{
	int x,y,len,wait;
} Stair;
typedef struct{
	int x,y,num,dst;
} Person;
vector<Stair> s;
vector<Person> p;

queue<Person> v1;
vector<Person> v2;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct compare{
	bool operator()(const Person &a, const Person &b)
	{
		return a.dst>b.dst;
	}
};
bool cmp(Person &a, Person &b)
{
	return a.dst>b.dst;
}
int solve()
{
	int ret=-1;
	/*
	for(int i=0;i<p.size();i++)
	{
		printf("%d ", p[i].num);
	}
	printf("\n");
	*/
	priority_queue<Person,vector<Person>,compare> pq1;
	priority_queue<Person,vector<Person>,compare> pq2;
	for(int i=0;i<p.size();i++)
	{
		int idx = p[i].num-1;
		p[i].dst=abs(p[i].x-s[idx].x)+abs(p[i].y-s[idx].y);
		if(idx==0)
			pq1.push(p[i]);
		if(idx==1)
			pq2.push(p[i]);
	}
	
	int len1 = s[0].len;
	int len2 = s[1].len;
	int st[3]={0,};
	int count =0;
	while(!pq1.empty())
	{
		int dst = pq1.top().dst;
		pq1.pop();
		if(dst<st[count%3])
			dst = st[count%3]+s[0].len;
		else
			dst+=s[0].len+1;
		st[count%3]=dst;
		ret = max(ret,st[count%3]);
		count++;
	}
	memset(st,0,sizeof(st));
	count=0;
	while(!pq2.empty())
	{
		int dst = pq2.top().dst;
		pq2.pop();
		if(dst<st[count%3])
			dst = st[count%3]+s[1].len;
		else
			dst+=s[1].len+1;
		st[count%3]=dst;
		ret = max(ret,st[count%3]);
		count++;
	}

	return ret;
}
int ans=INT_MAX;
void dfs(int n)
{
	if(n==p.size())
	{
		ans=min(ans,solve());
		return ;
	}
	for(int i=1;i<=s.size();i++)
	{
		p[n].num=i;
		dfs(n+1);
	}
}
int main()
{
	scanf("%d", &T);
	for(int t=1;t<=T;t++)
	{
		memset(map,0,sizeof(map));
		p.clear();
		s.clear();
		ans=INT_MAX;
		scanf("%d", &N);
		int num=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				scanf("%d", &map[i][j]);
				if(map[i][j]==1){
					p.push_back({i,j,0,0});
				}
				if(map[i][j]>=2){
					s.push_back({i,j,map[i][j],0});
				}
			}
		}
		dfs(0);
		printf("#%d %d\n", t,ans);
	}
	return 0;
}
