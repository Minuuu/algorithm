#include<stdio.h>
#include<vector>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int T,M,A;
int dir[5][2]={{0,0},{-1,0},{0,1},{1,0},{0,-1}};
int userA[101];
int userB[101];
int chkA[9];
int chkB[9];
typedef struct bc{
	int x,y,c,p;
} BC;
vector<BC> v;
int solve(int ax, int ay, int bx, int by)
{
	memset(chkA,0,sizeof(chkA));
	memset(chkB,0,sizeof(chkB));
	for(int i=0;i<A;i++)
	{
		if(v[i].c>=abs(ax-v[i].x)+abs(ay-v[i].y)){
			chkA[i]=1;
		}
		if(v[i].c>=abs(bx-v[i].x)+abs(by-v[i].y)){
			chkB[i]=1;
		}
	}
	int result=-1;
	for(int i = 0; i < A; i++) {
		for(int j = 0; j < A; j++) {
			int temp = 0;
			if(i == j) {
				if(chkA[i] || chkB[j])
					temp = v[i].p;
			}
			else {
				if(chkA[i]){
					temp += v[i].p;
				}
				if(chkB[j]){
					temp += v[j].p;
				}
			}
			result = max(result,temp);
		}
	}
	return result;
}
int main()
{
	scanf("%d", &T);
	for(int t=1;t<=T;t++)
	{
		int x, y, c, p;
		scanf("%d %d", &M, &A);
		memset(userA,0,sizeof(userA));
		memset(userB,0,sizeof(userB));
		for(int i=1;i<=M;i++)
			scanf("%d", &userA[i]);
		for(int i=1;i<=M;i++)
			scanf("%d", &userB[i]);
		for(int i=0;i<A;i++)
		{
			scanf("%d %d %d %d", &y, &x, &c, &p);
			v.push_back({x,y,c,p});
		}
		int res = solve(1,1,10,10);
		int ax=1;
		int ay=1;
		int bx=10;
		int by=10;
		for(int i=1;i<=M;i++)
		{
			ax+=dir[userA[i]][0];
			ay+=dir[userA[i]][1];
			bx+=dir[userB[i]][0];
			by+=dir[userB[i]][1];
			res+=solve(ax,ay,bx,by);
		}
		printf("#%d %d\n", t, res);
		v.clear();
	}
	return 0;
}
