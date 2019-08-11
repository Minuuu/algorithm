#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
stack<char> s;
int main()
{
	char str[50];
	scanf("%s", str);
	int sum = 1;
	int ans = 0;
	int flag = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ')')
		{
			if (!s.empty()) {
				if (s.top() == '(')
				{
					s.pop();
					if (str[i - 1] == '(')
					{
						ans += sum;
					}
					sum /= 2;
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else {
				flag = 1;
				break;
			}
		}
		else if (str[i] == ']')
		{
			if (!s.empty())
			{
				if (s.top() == '[')
				{
					if (str[i - 1] == '[')
					{
						ans += sum;
					}
					s.pop();
					sum /= 3;
				}
				else {
					flag = 1;
					break;
				}
			}
			else {
				flag = 1;
				break;
			}
		}
		else if (str[i] == '(')
		{
			sum *= 2;
			s.push(str[i]);
		}
		else if (str[i] == '[')
		{
			sum *= 3;
			s.push(str[i]);
		}
		//printf("sum: %d\nans: %d\n", sum,ans);
	}
	if (flag == 1||!s.empty())
		ans = 0;
	printf("%d\n", ans);
	return 0;
}
