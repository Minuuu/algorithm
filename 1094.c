#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int X;
	scanf("%d", &X);
	int cnt=1;
	int div = X/2;
	int minN=64;
	int sum=64;
	while(X!=64)
	{
		minN=minN/2;
		cnt++;
		if(sum-minN>=X)
		{
			sum-=minN;
			cnt--;
		}
		if(sum==X){
			break;
		}
	}
	printf("%d", cnt);
	return 0;
}
