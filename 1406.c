#include<stdio.h>
#include<deque>
using namespace std;
deque<char> dq,tmp;
int main()
{
	char str[100005];
	while(1)
	{
		char c;
		scanf("%c", &c);
		if(c=='\n')
			break;
		dq.push_back(c);
	}
	int n;
	scanf("%d", &n);
	while(n--)
	{
		char c;
		scanf(" %c", &c);
		if(c=='L')
		{
			if(dq.empty()==0){
				c = dq.back();
				dq.pop_back();
				tmp.push_front(c);
			}
		}
		else if(c=='D')
		{
			if(tmp.empty()==0)
			{
				c = tmp.front();
				tmp.pop_front();
				dq.push_back(c);
			}
		}
		else if(c=='B')
		{
			if(dq.empty()==0)
			{
				dq.pop_back();
			}
		}
		else if(c=='P')
		{
			scanf(" %c", &c);
			dq.push_back(c);
		}
			
	}
	while(!dq.empty())
	{
		char c = dq.front();
		dq.pop_front();
		printf("%c", c);
	}
	while(!tmp.empty())
	{
		char c = tmp.front();
		tmp.pop_front();
		printf("%c", c);
	}

	return 0;
}
