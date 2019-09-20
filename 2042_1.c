#include<stdio.h>
long long tree[1000001*4];
int TN;
long long query(int ql, int qr, int idx, int l, int r)
{
	if(ql<=l&&r<=qr)
		return tree[idx];
	if(r<ql||qr<l)
		return 0;
	return query(ql,qr,2*idx,l,(l+r)/2)+query(ql,qr,2*idx+1,(l+r)/2+1,r);
}
void update(int idx, int val)
{
	tree[idx+TN-1] = val;
	idx = idx+TN-1;
	for(int i = idx/2;i>0;i/=2)
	{
		tree[i] = tree[2*i]+tree[2*i+1];
	}
}
int main()
{
	int n,m,k;
	scanf("%d %d %d", &n, &m, &k);
	for(TN=1;TN<n;TN<<=1);
	for(int i=1, x;i<=n;i++)
	{
		scanf("%d", &x);
		tree[TN+i-1] = x;
	}
	for(int i = TN-1;i>0;i--)
		tree[i] = tree[2*i]+tree[2*i+1];
	printf("%d\n", TN);
	for(int i=0;i<20;i++)
		printf("%lld\n", tree[i]);
	for(int i=0,a,b,c;i<m+k;i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if(a==1)
			update(b,c);
		else
			printf("%lld\n", query(b,c,1,1,TN));
	}
	return 0;
}
