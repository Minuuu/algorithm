#include<stdio.h>
int n,m;
int parent[100001];
int weight[100001];
int find(int num)
{
	if(parent[num]==num)
		return num;
	else{
		int tmp = find(parent[num]);
		weight[num] += weight[parent[num]];
		return parent[num]=tmp;
	}
}
int main()
{

	while(1){
		for(int i=0;i<=100000;i++)
			parent[i]=i;
		for(int i=1;i<=100000;i++)
			weight[i]=0;
		scanf("%d %d", &n, &m);
		if(n==0&&m==0)
			break;
		for(int i=0;i<m;i++)
		{
			char c;
			scanf(" %c", &c);
			if(c=='!'){
				int a,b,w;
				scanf("%d %d %d", &a,&b,&w);
				int ra = find(a);
				int rb = find(b);
				if(ra!=rb){
					weight[rb] = w+weight[a]-weight[b];
					parent[rb] = ra;
				}
			}
			else if(c=='?'){
				int a,b;
				scanf("%d %d", &a, &b);
				int ra = find(a);
				int rb = find(b);
				if(ra!=rb)
					printf("UNKNOWN\n");
				else{
					printf("%d\n", weight[b]-weight[a]);
				}
			}
		}
	}
	return 0;
}
