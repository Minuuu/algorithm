#include<stdio.h>
long long S;
int main()
{
	scanf("%ld", &S);
	long long sum=0;
	long long idx=2;
	for(long long i=1;i<=S;i++)
	{
		sum+=i;
		if(sum>S){
			idx=i;
			break;
		}
	}
	printf("%lld\n", idx-1);
	return 0;
}
