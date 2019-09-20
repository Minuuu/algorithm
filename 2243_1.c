#include<stdio.h>
#include<math.h>
#define MAX 1000000
long long tree[MAX*4];
int TN;
void update(int idx, int val)
{
	for(idx = TN+idx-1;idx>0;idx>>=1)
		tree[idx]+=val;
}
long long query(int l, int r, int idx, int val)
{
	if(l==r){
		return l;
	}
	if(val<=tree[idx*2]){
		return query(l,(l+r)/2,2*idx,val);
	}
	else{
		return query((l+r)/2+1,r,idx*2+1,val-tree[idx*2]);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for(TN=1;TN<1000000;TN<<=1);
	for(int i=0;i<n;i++)
	{
		int op;
		scanf("%d", &op);
		if(op==2)
		{
			//update
			int b,c;
			scanf("%d %d", &b, &c);
			update(b,c);
		}
		else{
			//query
			int r;
			scanf("%d", &r);
			int idx = query(1,TN,1,r);
			printf("%d\n", idx);
			update(idx,-1);
		}
	}
	return 0;
}
