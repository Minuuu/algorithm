#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int mintree[400001];
int maxtree[400001];
int minquery(int ql, int qr, int idx, int l , int r)
{
	if(ql<=l&&r<=qr)
		return mintree[idx];
	if(r<ql || qr<l)
		return 0x3f3f3f3f;
	return min(minquery(ql,qr,idx*2,l, (l+r)/2),minquery(ql,qr,idx*2+1,(l+r)/2+1,r));
}
int maxquery(int ql, int qr, int idx, int l , int r)
{
    if(ql<=l&&r<=qr)
        return maxtree[idx];
    if(r<ql || qr<l)
        return 0;
    return max(maxquery(ql,qr,idx*2,l, (l+r)/2),maxquery(ql,qr,idx*2+1,(l+r)/2+1,r));
}
int N,M,TN;
int main()
{
	scanf("%d %d", &N, &M);
	for(TN=1;TN<N;TN<<=1);
	memset(mintree,0x3f,sizeof(mintree));
	for(int i=1, x;i<=N;i++)
	{
		scanf("%d", &x);
		mintree[TN+i-1] = x;
		maxtree[TN+i-1] = x;
	}

	for(int i=TN-1;i>0;i--)
	{
		mintree[i] = min(mintree[2*i], mintree[2*i+1]);
		maxtree[i] = max(maxtree[2*i], maxtree[2*i+1]);
	}
	for(int i=1;i<=M;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		printf("%d %d\n", minquery(a,b,1,1,TN), maxquery(a,b,1,1,TN));
	}

	return 0;
}
