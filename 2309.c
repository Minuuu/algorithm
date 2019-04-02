#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
int dwarf[10];
int visit[10];
int flag=0;
using namespace std;
vector<int> v;
void solve(int idx, int sum, int cnt)
{
	if(sum==100&&cnt==7)
	{
		int cnt=0;
		if(v.empty()){
			for(int i=1;i<=9;i++)
			{
				if(visit[i]==1){
					v.push_back(dwarf[i]);
				}
			}
		}
		flag=1;
		return ;
	}
	if(idx>=10)
		return ;
	if(flag==1)
		return;
	visit[idx]=1;
	solve(idx+1,dwarf[idx]+sum,cnt+1);
	visit[idx]=0;
	solve(idx+1,sum,cnt);
}
int main()
{
	int num;
	for(int i=1;i<=9;i++)
	{
		scanf("%d", &dwarf[i]);
	}
	solve(1,0,0);
	sort(v.begin(),v.end());
	for(int i=0;i<7;i++)
		printf("%d ", v[i]);
}
