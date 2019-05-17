#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d", &n);
	while(n--){
		int sum=0;
		int score=1;
		char str[80];
		scanf("%s", str);
		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]=='O')
			{
				sum+=score;
				score++;
			}
			else
				score=1;
		}
		printf("%d\n", sum);
	}
	return 0;
}
