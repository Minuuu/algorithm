#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[16];
int b[16];
int c[16];
int n;
int ans=0;
void solve(int r)
{
	if(r>n){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
			continue;
		if(b[r+i]==1||c[r-i+n]==1)
			continue;
		a[i]=b[r+i]=c[r-i+n]=1;
		solve(r+1);
		a[i]=b[r+i]=c[r-i+n]=0;
	}

}
int main()
{
	scanf("%d", &n);
	int res=0;
		solve(1);
	printf("%d\n", ans);
	return 0;
}
