#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int num=i;
		int tmp=1001;
		int flag = 0;
		while(num>=10)
		{
			int mod = num%10;
			num/=10;
			if(tmp!=1001 && tmp != mod - num%10){
				flag=1;
				break;
			}
			else{
				tmp=mod-num%10;
			}
		}
		if(flag==0){
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
