#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node{
	int x,y;
	bool operator < (const node &n1) const
	{
		if(n1.y==y)
			return x<n1.x;
		return y<n1.y;
	}
} Node;
int N;
Node n[100001];
int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d", &n[i].x, &n[i].y);
	}
	sort(n,n+N);
	for(int i=0;i<N;i++)
	{
		printf("%d %d\n", n[i].x, n[i].y);
	}
	return 0;
}
