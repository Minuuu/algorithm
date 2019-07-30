#include<stdio.h>
#include<algorithm>
#include<string.h>
char c1[1005];
char c2[1005];
int s1, s2;
int d[1005][1005];

int main()
{
	scanf("%s %s", c1+1, c2+1);
	s1 = strlen(c1+1);
	s2 = strlen(c2+1);
	
	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j<=s2; j++) {
			if (c1[i] == c2[j]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = std::max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}

	int x = s1 ;
	int y = s2 ;
	printf("%d\n", d[x][y]);
	char ans[1001] = { 0, };
	int idx = 0;
	while (d[x][y]) {
		if (d[x][y] == d[x - 1][y])
			x--;
		else if (d[x][y] == d[x][y - 1])
			y--;
		else {
			ans[idx++] = c1[x];
			x--;
			y--;
		}
	}
	for (int i = idx - 1; i >= 0; i--) {
		printf("%c", ans[i]);
	}

	return 0;
}
