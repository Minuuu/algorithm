#include<stdio.h>
#include<string.h>
int getSum(char c)
{
	int ans = 2;
	if(c>='A'&&c<='C')
		ans=3;
	else if(c>='D'&&c<='F')
		ans=4;
	else if(c>='G'&&c<='I')
		ans=5;
	else if(c>='J'&&c<='L')
		ans=6;
	else if(c>='M'&&c<='O')
		ans=7;
	else if(c>='P'&&c<='S')
		ans=8;
	else if(c>='T'&&c<='V')
		ans=9;
	else if(c>='W'&&c<='Z')
		ans=10;
	else
		ans=11;
	return ans;
}
int main()
{
	char str[20];
	scanf("%s", str);
	int ans=0;
	for(int i=0;i<strlen(str);i++)
		ans+=getSum(str[i]);
	printf("%d\n", ans);
	return 0;
}
