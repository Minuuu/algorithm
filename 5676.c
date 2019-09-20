#include<stdio.h>
#include<string.h>
int TN;
int tree[100000*4];
void update(int idx, int val)
{
	tree[TN+idx-1] = val;
	for(idx = (TN+idx-1)>>1;idx>0;idx>>=1)
	{
		tree[idx]=tree[2*idx]*tree[2*idx+1];
	}
}
int query(int ql, int qr, int idx, int l, int r)
{
	if(ql<=l&&r<=qr)
	{
		return tree[idx];
	}
	if(r<ql||qr<l)
		return 1;

	return query(ql,qr,2*idx,l,(l+r)/2)*query(ql,qr,2*idx+1,(l+r)/2+1,r);
}
int check(int val)
{
	if(val>0)
		return 1;
	else if(val<0)
		return -1;
	return 0;
}
int main()
{
	int n,k;
	while(scanf("%d %d", &n, &k)!=EOF)
	{
		for(TN=1;TN<n;TN<<=1);
		for(int i=0,x;i<n;i++)
		{
			scanf("%d", &x);
			if(x>0)
				tree[TN+i] = 1;
			else if(x<0)
				tree[TN+i] = -1;
			else
				tree[TN+i] = 0;
		}
		for(int i = TN-1;i>0;i--)
			tree[i] = tree[2*i]*tree[2*i+1];
		while(k--)
		{
			char c;
			int a,b;
			scanf(" %c %d %d", &c, &a, &b);
			if(c=='C')
			{
				b = check(b);
				update(a,b);
			}
			else if(c=='P')
			{
				int ret = query(a,b,1,1,TN);
			//	printf("%lld\n", ret);
				char c = '0';
				if(ret>0)
					c = '+';
				else if(ret<0)
					c = '-';
				printf("%c", c);
			}
		}
		printf("\n");
	}
	return 0;
}
