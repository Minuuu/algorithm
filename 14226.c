#include<stdio.h>
#include<queue>
using namespace std;
int visit[2001][2001];
int main()
{
	int s;
	scanf("%d", &s);
	queue<pair<int,int>> q;
	q.push({1,0});
	int cnt = 0;
	visit[1][0] = 1;
	while(!q.empty())
	{
		int size = q.size();
		for(int i=0;i<size;i++){
			int num = q.front().first;
			int clip = q.front().second;
			q.pop();
			if(num==s)
			{
				printf("%d\n", cnt);
				return 0;
			}
			q.push({num,num});
			if(num+clip<=2000&&!visit[num+clip][clip]&&clip!=0)
			{
				visit[num+clip][clip] = 1;
				q.push({num+clip,clip});
			}
			if(!visit[num-1][clip]&&num-1>0)
			{
				visit[num-1][clip] = 1;
				q.push({num-1,clip});
			}
		}
		cnt++;
	}
	return 0;
}
