#include<stdio.h>
#include<string.h>
char str[101];
int main()
{
	int n;
	int cnt=0;
	scanf("%d", &n);
	while(n--)
	{
		char alp[26]={0,};
		int flag=0;
		scanf("%s", str);
		for(int j=0;j<strlen(str);j++){
			if(alp[str[j]-'a']!=0){
				flag=1;
				break;
			}
			for(int i=j;i<strlen(str);i++)
			{
				if(str[j]!=str[i])
				{
					alp[str[j]-'a']=1;
					j=i-1;
					break;
				}
			}
		}
		if(!flag)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
