#include<stdio.h>
int N,A,B;
int main()
{
	scanf("%d %d %d", &N, &A, &B);
	int dn=N;
	int da=A-1;
	int db=B-1;
	int cnt=0;
	while(1)
	{
		int all=dn/2;
		int kim=da/2;
		int im=db/2;
		
		cnt++;
		if(kim==im)
			break;
		else{
			da/=2;
			db/=2;
		}

	}
	printf("%d\n", cnt);

	return 0;
}
