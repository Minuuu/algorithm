#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[501];
int time[501];
int chk[501];
int myans = 0;
int getAns(int num) {

	if (chk[num] != 0) {
		return chk[num];
	}

	for (int i = 0; i < v[num].size(); i++) {
		int tmp = v[num][i];
		chk[num] = max(chk[num], getAns(tmp));
	}
	return chk[num] += time[num];
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		time[i + 1] = t;
		while (1) {
			int num;
			scanf("%d", &num);
			if (num == -1)
				break;
			v[i + 1].push_back(num);
		}
	}
	for (int i = 1; i <= n; i++) {
		myans = getAns(i);
		printf("%d\n", myans);
	}
	
	return 0;
}
