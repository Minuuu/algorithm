#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	while(1)
	{
		int n;
		scanf("%d", &n);
		long long arr[100001];
		long long ans = -1;
		stack<long long> s;
		if(n==0)
			break;
		for(int i=0;i<n;i++)
			scanf("%lld", arr+i);
		for(int i=0;i<n;i++)
		{
			if(s.empty()||arr[s.top()]<=arr[i])
				s.push(i);
			else
			{
				while(!s.empty()&&arr[s.top()]>arr[i])
				{
					long long h = arr[s.top()];
					s.pop();
					long long w = i;
					if(!s.empty())
						w = i-s.top()-1;
					ans = max(ans,h*w);
				}
				s.push(i);
			}
		}
		//printf("siuze: %d\n", s.size());
		while(!s.empty())
		{
			long long h = arr[s.top()];
			//printf("%lld\n", s.top());
			s.pop();
			long long w = n;
			if(!s.empty()){
				w = n-s.top()-1;
			}
			//printf("h*w: %lld\n", h*w);
			ans = max(ans,h*w);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
