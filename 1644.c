#include<stdio.h>
int prime[4000001];
int save[4000001];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 2; i <= num; i++)
		prime[i] = 1;
	
	for (int i = 2; i <= num; i++) {
		for (int j = i + i; j <= num; j+=i) {
			if (prime[j] == 1)
				prime[j] = 0;
		}
	}
	int idx = 0;
	for (int i = 1; i <= num; i++) {
		if (prime[i] == 1)
			save[idx++] = i;
	}
	int s = 0, e = 0;
	int sum = 0, ans = 0;
	while (1)
	{
		if (sum < num) {
			if (e >= idx)
				break;
			sum += save[e++];
		}
		else
			sum -= save[s++];
		if (sum == num)
			ans++;

	}
	printf("%d\n", ans);

	return 0;
}
