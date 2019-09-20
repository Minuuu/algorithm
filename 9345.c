#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int mintree[100001*4];
int maxtree[100001*4];
int TN;
pair<int,int> query(int ql, int qr, int idx, int l, int r)
{
	if(ql<=l&&r<=qr)
		return {mintree[idx],maxtree[idx]};
	if(r<ql||qr<l)
		return {0x3f3f3f3f,0};
	pair<int,int> r1 = query(ql,qr,idx*2,l,(l+r)/2);
	pair<int,int> r2 = query(ql,qr,idx*2+1,(l+r)/2+1,r);
	return {min(r1.first,r2.first),max(r1.second,r2.second)};
}
void update(int idx1, int idx2)
{
	for(int i = (TN+idx1)/2;i>0;i>>=1)
	{
		mintree[i] = min(mintree[2*i],mintree[2*i+1]);
		maxtree[i] = max(maxtree[2*i],maxtree[2*i+1]);
	}
	for(int i = (TN+idx2)/2;i>0;i>>=1)
	{
		mintree[i] = min(mintree[2*i],mintree[2*i+1]);
		maxtree[i] = max(maxtree[2*i],maxtree[2*i+1]);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,k;
		scanf("%d %d", &n, &k);
		for(TN=1;TN<n;TN<<=1);
		memset(mintree,0x3f,sizeof(mintree));
		memset(maxtree,0x3f,sizeof(maxtree));
		for(int i=1;i<=n;i++)
		{
			mintree[TN+i-1] = i;
			maxtree[TN+i-1] = i;
		}
		for(int i = TN-1;i>0;i--)
		{
			mintree[i] = min(mintree[i*2],mintree[i*2+1]);
			maxtree[i] = max(maxtree[i*2],maxtree[i*2+1]);
		}
		for(int i=0;i<k;i++)
		{
			int q,a,b;
			scanf("%d %d %d", &q, &a, &b);
			if(q==0)//update
			{
				swap(mintree[TN+a],mintree[TN+b]);
				swap(maxtree[TN+a],maxtree[TN+b]);
				update(a,b);
			}
			else//query
			{
				pair<int,int> ret = query(a+1,b+1,1,1,TN);
			//	printf("ret: %d %d\n", ret.first, ret.second);
				if(ret.first==a+1&&ret.second==b+1)
					printf("YES\n");
				else
					printf("NO\n");
			}

		}
	}
	return 0;
}
