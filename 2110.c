#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int N,C;
	scanf("%d %d", &N, &C);
	int arr[200005]={0,};
	for(int i=0;i<N;i++)
		scanf("%d", arr+i);
	sort(arr,arr+N);
	int r = arr[N-1]-arr[0];
	int l = 1;
	int ans = 0;
	while(l<=r)
	{
		int mid = (l+r)/2;
		int cnt = 1;
		int pos = arr[0];
		//printf("mid: %d\n", mid);
		for(int i=1;i<N;i++)
		{
			if(arr[i]-pos>=mid)
			{
				cnt++;
				pos = arr[i];
			}
		}
		//printf("cnt: %d\n", cnt);
		if(cnt>=C)
		{
			ans = max(mid,ans);
			l = mid+1;
		}
		else
			r = mid - 1;
	}
	printf("%d\n", ans);

	return 0;
}
