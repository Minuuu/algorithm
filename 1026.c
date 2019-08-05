#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
	int n;
	int A[101]={0,};
	int B[101]={0,};
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", A+i);
	}
	for(int i=0;i<n;i++)
		scanf("%d", B+i);
	sort(A,A+n,greater<int>());
	sort(B,B+n);
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=A[i]*B[i];
	printf("%d\n", sum);
	return 0;
}
