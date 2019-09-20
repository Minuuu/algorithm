#include<cstdio>
int TN;
int tree[65540*4];
int a[250001];
void update(int idx, int val)
{
	tree[TN+idx] += val;
	for(idx = (TN+idx)/2;idx>0;idx>>=1)
		tree[idx] = tree[idx*2]+tree[idx*2+1];
}
int query(int l, int r, int idx, int val)
{
	if(l==r){
		return l;
	}
	if(tree[2*idx]>=val)
		return query(l,(l+r)/2,idx*2,val);
	else
		return query((l+r)/2+1,r,idx*2+1,val-tree[2*idx]);
}
int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	for(TN=1;TN<65536;TN<<=1);
	//printf("TN: %d\n", TN);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &a[i]);
		update(a[i],1);
		if(i>=k)
		{
			ans +=query(0,65535,1,(k+1)/2);
	//		printf("idx: %d\n", i-k+1);
			update(a[i-k+1],-1);
		}
		//printf("ans: %lld\n", ans);
	}
	printf("%lld\n", ans);
	return 0;
}
