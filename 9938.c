#include<stdio.h>
int chk[300001];
int parent[300001];
int find(int num)
{
	if(num==parent[num])
		return num;
	return parent[num] = find(parent[num]);
}
void merge(int a,int b)
{
	int ra = find(a);
	int rb = find(b);
	parent[ra] = rb;
	printf("LADICA\n");
}
int main()
{
	int N,L;
	scanf("%d %d", &N, &L);
	for(int i=1;i<=L;i++)
		parent[i] = i;
	for(int i=0;i<N;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		if(!chk[a])
		{
			chk[a]=1;
			merge(a,b);
		}
		else if(!chk[b])
		{
			chk[b] = 1;
			merge(b,a);
		}
		else if(!chk[find(a)])
		{
			chk[find(a)] = 1;
			merge(a,b);
		}
		else if(!chk[find(b)])
		{
			chk[find(b)] = 1;
			merge(b,a);
		}
		else
			printf("SMECE\n");
	}
	return 0;
}
