#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int T,N;
int map[1001];
int main()
{
	T=10;
	for(int i=1;i<=T;i++)
	{
		int ans=0;
		scanf("%d", &N);
		memset(map,0,sizeof(map));
		for(int j=1;j<=N;j++){
			scanf("%d", &map[j]);
		}
		for(int j=3;j<=N-2;j++){
			if(map[j]>map[j-1]&&map[j]>map[j-2]&&map[j]>map[j+1] && map[j]>map[j+2])
			{
				int a = max(map[j-1],map[j-2]);
				int b = max(map[j+1],map[j+2]);
				ans+=map[j]-max(a,b);
			}
		}
		printf("#%d %d\n", i,ans);
	}
	return 0;
}
