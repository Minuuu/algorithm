#include<stdio.h>
long long tree[1000005*4];
long long arr[1000005];
long long update(int left, int right, int node, long long val, int idx){
	if(!(left<=idx&&idx<=right))
		return tree[node] ;
	if(left==right)
		return tree[node]+=val;
	long long mid = (left+right)/2;
	long long r1 = update(left,mid,2*node,val,idx);
	long long r2 = update(mid+1,right,2*node+1,val,idx);
	return tree[node] = r1+r2;
}
long long query(int left, int right, int node, int start, int end)
{
	if(end<left||start>right)
		return 0;
	if(start<=left&&right<=end)
		return tree[node];
	int mid = (left+right)/2;
	return query(left,mid,2*node,start,end)+query(mid+1,right,2*node+1,start,end);
}
int main()
{
	int n,m,k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d", &num);
		arr[i+1]=num;
		update(1,n,1,num,i+1);	
	}
	for(int i=0;i<m+k;i++)
	{
		long long op, a,b;
		scanf("%lld %lld %lld", &op, &a, &b);
		if(op==1)
		{
			long long diff = b-arr[a];
			update(1,n,1,diff,a);
			arr[a]=b;
		}
		else{
			printf("%lld\n", query(1,n,1,a,b));
		}
	}
	
	return 0;
}
