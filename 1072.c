#include<stdio.h>
#define MAX 1000000000
int main()
{
	long long X,Y;
	scanf("%lld %lld", &X, &Y);
	int Z = Y*100/X;
	if(Z>=99)
		printf("-1\n");
	else{
		long long l=0;
		long long h = MAX;
		while(l<=h){
			long long a = (l+h)/2;
			long long tmp = (100*(Y+a))/(X+a);
			if(tmp-Z>=1)
			{
				h = a-1;
			}
			else{
				l = a+1;
			}
		}
		printf("%lld\n", l);
	}
	return 0;
}
