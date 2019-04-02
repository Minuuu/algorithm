#include<stdio.h>
int ppl[51][2];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d", &ppl[i][0], &ppl[i][1]);
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=1;
		for(int j=1;j<=n;j++)
		{
			if(ppl[i][0]<ppl[j][0]&&ppl[i][1]<ppl[j][1])
				cnt++;
		}
		printf("%d ", cnt);
	}
	return 0;
}
