#include<stdio.h>
int K;
int map[13];
int ans[8];
void dfs(int idx,int lvl)
{
	if(lvl==7)
	{
		for(int i=1;i<=6;i++)
			printf("%d ", ans[i]);
		printf("\n");
		return ;
	}
	for(int i=idx;i<=K;i++)
	{
		ans[lvl]=map[i];
		dfs(i+1,lvl+1);
	}
}
int main()
{
	while(1)
	{
		scanf("%d", &K);
		if(K==0)
			break;
		for(int i=1;i<=K;i++)
		{
			scanf("%d", &map[i]);
		}
		dfs(1,1);
		printf("\n");
	}
	return 0;
}
