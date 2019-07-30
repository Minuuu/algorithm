#include<stdio.h>
#include<string.h>
int n;
int arr[101];
long long visit[101][40];
int dest = 0;
long long solve(int idx, long long sum)
{
	if (sum < 0||sum>20)
		return 0;
	
	if (idx == n-1)
	{
		if (sum == dest) {
			return  1;
		}

		return  0;
	}
	long long &ret = visit[idx][sum];
	if (ret!=-1)
		return ret;
	
	ret = solve(idx + 1, sum + arr[idx+1]);
	ret += solve(idx + 1, sum - arr[idx+1]);
	return ret;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	scanf("%d", &dest);
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 21; j++)
			visit[i][j] = -1;
	printf("%lld\n", solve(1,arr[1]));
	return 0;
}
