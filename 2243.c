#include<stdio.h>
#include<math.h>
#define max  1000001
long long seg[max*4];
void update(int left, int right, int node, int idx, long long diff)
{
	if(!(left<=idx&&idx<=right))
		return ;
	seg[node]+=diff;
	if(left==right)
		return ;
	long long mid = (left+right)/2;
	update(left,mid,2*node,idx,diff);
	update(mid+1,right,2*node+1,idx,diff);
}
long long query(int left, int right, int node, int num)
{
	if(left==right){
		return left;
	}
	int mid = (left+right)/2;
	if(num<=seg[node*2]){
		return query(left,mid,2*node,num);
	}
	else{
		return query(mid+1,right,2*node+1,num-seg[node*2]);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int op;
		scanf("%d", &op);
		if(op==2)
		{
			//update
			int b,c;
			scanf("%d %d", &b, &c);
			update(1,max-1,1,b,c);
		}
		else{
			//query
			long long r;
			scanf("%lld", &r);
			long long idx = query(1,max-1,1,r);
	//		update(1,max-1,1,idx,-1);
			printf("%lld\n", idx);
		}
		/*
		for(int i=1;i<=n;i++)
			printf("%lld ", seg[i]);
		printf("\n");
		*/
	}
	return 0;
}
