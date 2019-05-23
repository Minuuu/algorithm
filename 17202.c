#include<stdio.h>
#include<string.h>
int main()
{
	char str1[9]={0,};
	char str2[9]={0,};
	char sum[17]={0,};
	int ans=0;
	scanf("%s", str1);
	scanf("%s", str2);
	for(int i=0;i<15;i+=2)
	{
		sum[i]=str1[i/2];
		sum[i+1]=str2[i/2];
	}
	for(int j=0;j<14;j++)
	{
		for(int i=0;i<strlen(sum)-1;i++)
		{
			sum[i]=(sum[i]-'0'+sum[i+1]-'0')%10+'0';
		}
	}
	printf("%c%c\n", sum[0],sum[1]);
	return 0;
}
