#include<stdio.h>
#include<string.h>
int arr[100001];
int visit[100001];
int cycle[100001];
int n;
int cnt=0;
void getCount(int idx, int num)
{
	cnt++;
	if(idx==num)
		return;
	getCount(arr[idx],num);
		
}
void dfs(int idx)
{
	visit[idx]=1;
	if(visit[arr[idx]]==0)
		dfs(arr[idx]);
	else{
		if(cycle[arr[idx]]==0){
			getCount(arr[idx],idx);
		}
	}
	cycle[idx] = 1;
	return ;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		memset(arr,0,sizeof(arr));
		memset(visit,0,sizeof(visit));
		memset(cycle,0,sizeof(cycle));
				
		for(int i=1;i<=n;i++)
			scanf("%d", arr+i);
		cnt=0;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(visit[i]==0)
			{
				dfs(i);
			}
		}
		/*
		for(int i=1;i<=n;i++)
			printf("%d ", visit[i]);
		printf("\n");
		printf("cnt: %d\n", cnt);
		*/
		printf("%d\n", n-cnt);

	}
	return 0;
}
