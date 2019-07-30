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
	}
	
	printf("%d\n", v.size());
	
	return 0;
}
