#include<stdio.h>
#include<vector>
#include<algorithm>

int arr[1000001];
int d[1000001];
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	vector<int> v;
	v.push_back(arr[1]);
	d[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (v[v.size() - 1] < arr[i])
		{
			v.push_back(arr[i]);
			d[i] = v.size();
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[idx] = arr[i];
			d[i] = idx+1;
		}
		/*
		int idx = -1;
		int cnt = 1;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] >= arr[i])
			{
				idx = j;
				break;
			}
			cnt++;
		}
		if (idx == -1) {
			v.push_back(arr[i]);
			d[i] = v.size();
		}
		else {
			v[idx] = arr[i];
			d[i] = cnt;
		}
		*/
	}
	/*
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");

	for (int i = 1; i<=n;i++)
		printf("%d ", d[i]);
	printf("\n");
	*/
	int num = v.size();
	vector<int> v1;
	for (int i = n; i >= 1; i--)
	{
		if (d[i] == num)
		{
			v1.push_back(arr[i]);
			num--;
		}
	}
	printf("%d\n", v.size());
	for (int i = v1.size() - 1; i >= 0; i--)
		printf("%d ", v1[i]);
	

	return 0;
}
