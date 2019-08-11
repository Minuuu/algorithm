#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
stack<char> s;
char str[40];
int main()
{
	scanf("%s", str);
	int ans = 0;
	int sum=1;
	int flag = 0;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]=='(')
		{
			s.push('(');
			sum*=2;
		}
		else if(str[i]=='[')
		{
			s.push('[');
			sum*=3;
		}
		else if(str[i]==')')
		{
			if(!s.empty())
			{
				if(s.top()=='(')
				{
					s.pop();
					if(str[i-1]=='(')
						ans+=sum;
					sum/=2;
				}
				else
				{
					flag = 1;
					break;
				}

			}
			else
			{
				flag = 1;
				break;
			}
		}
		else if(str[i]==']')
		{
			if(!s.empty())
			{
				if(s.top()=='[')
				{
					s.pop();
					if(str[i-1]=='[')
						ans+=sum;
					sum/=3;
				}
				else{
					flag = 1;
					break;
				}

			}
			else
			{
				flag = 1;
				break;
			}
		}
	}
	if(flag==1||!s.empty())
		ans = 0;
	printf("%d", ans);
	return 0;
}
