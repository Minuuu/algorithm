#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char c[100]={0,};
	scanf("%s", c);
	for(int i=0;i<strlen(c);i++)
	{
		printf("%c",c[i]);
		if(i%10==9)
			printf("\n");
	}
	return 0;
}
