#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int N,M;
	int num=0;
	scanf("%d %d", &N, &M);
	num=M;
	int res=-1;
	for(int i=1;i<4;i++)
	{
		scanf("%d %d", &N, &M);
		num=num-N+M;
		if(num>10000)
			num=10000;
		res = max(num,res);
	}
	printf("%d\n", res);
	return 0;
}
