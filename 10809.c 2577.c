#include<stdio.h>
#include<string.h>
int main()
{
	int chk[26];
	char str[100];
	memset(chk,-1,sizeof(chk));
	scanf("%s", str);
	for(int i=0;i<strlen(str);i++)
		if(chk[str[i]-'a']==-1)
			chk[str[i]-'a']=i;
	for(int i=0;i<26;i++)
		printf("%d ", chk[i]);
	return 0;
}
