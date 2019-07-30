#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int prime[1010001];
int main()
{
	int n;
	scanf("%d", &n);
	prime[1]=1;
	for(int i=2;i<=1010000;i++)
	{
		for(int j=i+i;j<=1010000;j+=i){
			prime[j]=1;
		}
	}
	int ans=-1;
	for(int i=n;i<=1010000;i++){
		if(prime[i]==0){
			string str = to_string(i);
			int len = str.length();
			int flag=0;
			for(int j=0;j<len/2;j++)
			{
				if(str[j]!=str[len-j-1])
					flag=1;
			}
			if(flag==0)
			{
				ans=i;
				break;
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}
