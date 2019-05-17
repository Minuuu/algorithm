#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	char str[1000000]={0,};
	int chk[26]={0,};
	scanf("%s", str);

	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]>='a'&&str[i]<='z')
			chk[str[i]-'a']+=1;
		else if(str[i]>='A'&&str[i]<='Z')
			chk[str[i]-'A']+=1;
	}
	int tmp = *max_element(chk,chk+26);
	char c='?';
	int cnt=0;
	for(int i=0;i<26;i++)
	{
		if(tmp==chk[i])
		{
			c=i+'A';
			cnt++;
		}
		if(cnt>1)
		{
			c='?';
			break;
		}
	}
	printf("%c\n", c);
	return 0;
}
