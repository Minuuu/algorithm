#include<stdio.h>
#include<algorithm>
using namespace std;
int map[101][101];
int d[101][101][2][2];
/*
0,0 -> 북2번
0,1 -> 북1번
1,0 -> 동2번
1,1 -> 동1번
*/

int main()
{
	int w, h;
	scanf("%d %d", &w, &h);
	//위로가는경우 위로2번가는거 초기화
	for (int i = 2; i <= w; i++)
	{
		d[i][1][0][0] = 1;
	}
	//오른쪽가는경우 오른쪽2번가는거 초기화
	for (int i = 2; i <= h; i++)
		d[1][i][1][0] = 1;
	
	for (int i = 2; i <= w; i++)
	{
		
		for (int j = 2; j <= h; j++)
		{
			//북2번
			d[i][j][0][0] = (d[i - 1][j][0][0] + d[i - 1][j][0][1])%100000;
			//북1번
			d[i][j][0][1] = (d[i - 1][j][1][0]) % 100000;
			//동2번
			d[i][j][1][0] = (d[i][j - 1][1][0] + d[i][j - 1][1][1]) % 100000;
			//동1번
			d[i][j][1][1] = d[i][j - 1][0][0] % 100000;
		}
	}
	int res = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			res += d[w][h][i][j];	
	}
	printf("%d\n", res%100000);
	return 0;
}
