#include<stdio.h>
#include<deque>
using namespace std;
deque<int> dq;
int main()
{
	int n;
	int front=0;
	int rear=0;
	scanf("%d", &n);
	while(n--)
	{
		char str[20];
		scanf("%s", str);
		if(!strcmp(str,"push_back"))
		{
			int num;
			scanf("%d", &num);
			dq.push_back(num);
		}
		else if(!strcmp(str,"push_front"))
		{
			int num;
			scanf("%d", &num);
			dq.push_front(num);
		}
		else if(!strcmp(str,"front"))
		{
			if(!dq.empty())
				printf("%d\n", dq.front());
			else
				printf("%d\n", -1);
		}
		else if(!strcmp(str,"back"))
		{
			if(!dq.empty())
				printf("%d\n", dq.back());
			else
				printf("%d\n", -1);
		}
		else if(!strcmp(str,"size"))
		{
			printf("%d\n", dq.size());
		}
		else if(!strcmp(str,"empty"))
		{
			printf("%d\n", dq.empty());
		}
		else if(!strcmp(str,"pop_front"))
		{
			if(!dq.empty())
			{
				int num = dq.front();
				dq.pop_front();
				printf("%d\n", num);
			}
			else
				printf("-1\n");
		}
		else if(!strcmp(str,"pop_back"))
		{
			if(!dq.empty())
			{
				int num = dq.back();
				dq.pop_back();
				printf("%d\n", num);
			}
			else
				printf("-1\n");
		}
	}
}
