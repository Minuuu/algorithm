#include<stdio.h>
int arr[3][2];
int ccw() {
	return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0] + arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0] + arr[2][0] * arr[0][1] - arr[2][1] * arr[0][0];
}
int main()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	if (ccw() > 0)
		printf("1");
	else if (ccw() < 0)
		printf("-1");
	else
		printf("0");
	
	return 0;
}
