#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int arrMin[3] = { 0, };
	int arrMax[3] = { 0, };
	int ansMin[3] = { 0, };
	int ansMax[3] = { 0, };
	scanf("%d", &n);
	
	
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		for (int j = 0; j < 3; j++)
		{
			arrMin[j] = ansMin[j];
			arrMax[j] = ansMax[j];
		}

		ansMin[0] = min(arrMin[0], arrMin[1]) + a;
		ansMin[1] = min(arrMin[0], min(arrMin[2], arrMin[1])) + b;
		ansMin[2] = min(arrMin[1], arrMin[2]) + c;
		
		ansMax[0] = max(arrMax[0], arrMax[1]) + a;
		ansMax[1] = max(arrMax[0], max(arrMax[2], arrMax[1])) + b;
		ansMax[2] = max(arrMax[1], arrMax[2]) + c;

	}
	sort(ansMin, ansMin + 3);
	sort(ansMax, ansMax + 3);
	printf("%d %d", ansMax[2],ansMin[0]);
	return 0;
}
