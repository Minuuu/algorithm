#include<stdio.h>
int arr2[10001];
void postorder(int l, int e)
{
	if (l > e)
		return;
	int tmp = l+1;
	while (arr2[l] > arr2[tmp]) {
		tmp++;	
	}
	postorder(l + 1, tmp - 1);
	postorder(tmp, e);
	printf("%d\n", arr2[l]);
}
int main()
{
	int idx = 0,n;
	while (scanf("%d", &n) == 1) {
		arr2[idx++] = n;
	}

	arr2[idx] = 1e6;
	postorder(0, idx-1);
	return 0;
}
