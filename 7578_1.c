#include<stdio.h>
int TN;
int tree[1000000*4];
int a[500001];
int b[1000001];
int query(int ql, int qr, int idx, int l, int r)
{
	if(ql<=l&&r<=qr)
		return tree[idx];
	if(r<ql||qr<l)
		return 0;
	return query(ql,qr,idx*2,l,(l+r)/2)+query(ql,qr,idx*2+1,(l+r)/2+1,r);
}
void update(int idx, int val)
{
	tree[idx+TN-1] = val;
	for(idx = (idx+TN-1)/2;idx>0;idx>>=1)
		tree[idx] = tree[idx*2]+tree[idx*2+1];
}
void print()
{
	for(int i=1;i<=20;i++)
		printf("%d ", tree[i]);
	printf("\n");
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d", a+i);
	}
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d", &x);
		b[x] = i;
	}
	for(TN=1;TN<n;TN<<=1);
	long long ans = 0;
	for(int i = 1;i<=n;i++)
	{
		ans+= query(b[a[i]],TN, 1, 1,TN);
		update(b[a[i]], 1);
	//	print();
	}
	printf("%lld\n", ans);
	return 0;
}
