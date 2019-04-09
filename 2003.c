#include<stdio.h>
int N,M;
int arr[10001];
int main()
{
	scanf("%d %d", &N, &M);
	for(int i=1;i<=N;i++){
		scanf("%d", &arr[i]);
	}
	int s=1;
	int l=1;
	int sum=arr[s];
	int ans=0;
	while(l<=N)
	{
		printf("sum: %d %d\n", sum,l);
		if(sum==M)
		{
			ans++;
			sum-=arr[s];
			s++;
		}
		else if(sum>M)
		{
			sum-=arr[s];
			s++;
		}
		else{
			l++;
			sum+=arr[l];
		}
	}
	printf("ans: %d\n", ans);
	return 0;
}
