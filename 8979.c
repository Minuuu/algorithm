#include<stdio.h>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int n,k;
int map[1005][4];

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d", &a);
		for(int j=1;j<=3;j++)
		{
			scanf("%d", &map[a][j]);
		}
	}
	int gold = map[k][1];
	int silver = map[k][2];
	int blonze = map[k][3];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(map[i][1]>gold)
			cnt++;
		else if(map[i][1]==gold){
			if(map[i][2]>silver){
				cnt++;
			}
			else if(map[i][2]==silver){
				if(map[i][3]>blonze)
					cnt++;
			}
		}
	}
	printf("%d\n", cnt+1);
	return 0;
}
