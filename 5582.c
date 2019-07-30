#include<stdio.h>
#include<algorithm>
#include<string.h>
char c1[4005];
char c2[4005];
int s1, s2;
int d[4005][4005];
int ans = 0;
int main()
{
	scanf("%s %s", c1 + 1, c2 + 1);
	s1 = strlen(c1 + 1);
	s2 = strlen(c2 + 1);

	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			if (c1[i] == c2[j]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			ans = std::max(d[i][j], ans);
		}
	}

	printf("%d\n", ans);
	
	return 0;
}
