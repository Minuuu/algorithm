#include<stdio.h>
#define MOD  1000000007
int TN;
long long sumtree[200001*4];
long long cnttree[200001*4];
void update(int idx, int val)
{
	sumtree[TN+idx] +=val;
	cnttree[TN+idx]++;
	for(idx = (TN+idx)/2;idx>0;idx>>=1)
	{
		sumtree[idx] = sumtree[2*idx] + sumtree[2*idx+1];
		cnttree[idx] = cnttree[2*idx] + cnttree[2*idx+1];
	}
}
long long query_sum(int ql, int qr, int idx, int l, int r)
{
	if(ql<=l&&r<=qr)
		return sumtree[idx];
	if(r<ql||qr<l)
		return 0;
	return query_sum(ql,qr,2*idx,l,(l+r)/2)+query_sum(ql,qr,2*idx+1,(l+r)/2+1,r);
}
long long query_cnt(int ql, int qr, int idx, int l, int r)//나무개수
{
	if(ql<=l&&r<=qr)
		return cnttree[idx];
	if(r<ql||qr<l)
		return 0;
	return query_cnt(ql,qr,2*idx,l,(l+r)/2)+query_cnt(ql,qr,2*idx+1,(l+r)/2+1,r);
}
int main()
{
	int n;
	scanf("%d", &n);
	for(TN=1;TN<200001;TN<<=1);
	int x;
	long long ans = 1;
	scanf("%d", &x);
	update(x,x);
	for(int i=1;i<n;i++)
	{
		scanf("%d", &x);
		update(x,x);
		long long cnt1 = query_cnt(0,x-1,1,0,TN-1);
		long long sum1 = query_sum(0,x-1,1,0,TN-1);
		long long cnt2 = query_cnt(x+1,200001,1,0,TN-1);
		long long sum2 = query_sum(x+1,200001,1,0,TN-1);
		long long tmp = (cnt1*x-sum1)%MOD + (sum2-cnt2*x)%MOD;
		ans = ((ans%MOD)*(tmp%MOD))%MOD;
	}
	printf("%lld\n", ans%MOD);
	return 0;
}
