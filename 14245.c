#include<stdio.h>
int TN;
int tree[500001*4];
int query(int idx, int l, int r)
{
	int sum = 0;
	for(idx = (TN+idx);idx;idx>>=1)
		sum^=tree[idx];
	return sum;
}
void update(int ql, int qr, int val, int idx, int l, int r)
{
	if(r<ql||qr<l)
		return ;
	if(ql<=l&&r<=qr)
	{
		tree[idx]^=val;
		return ;
	}
	update(ql,qr,val,idx*2,l,(l+r)/2);
	update(ql,qr,val,idx*2+1,(l+r)/2+1,r);
}
int main()
{
	int n;
	scanf("%d", &n);
	for(TN=1;TN<n;TN<<=1);
	for(int i=0, a;i<n;i++)
	{
		scanf("%d", &a);
		tree[TN+i] = a;
	}
	int m;
	scanf("%d", &m);
	for(int i=1;i<=m;i++)
	{
		int t;
		scanf("%d", &t);
		if(t==1)
		{
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			update(a,b,c,1,1-1,TN-1);
		}
		else
		{
			int a;
			scanf("%d", &a);
			printf("%d\n", query(a,1,TN));
		}
	}
	return 0;
}
