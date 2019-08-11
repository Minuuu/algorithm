#include<stdio.h>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
stack<int> s;
vector<char> c;
int main()
{
	int n;
	scanf("%d", &n);
	int maxN=0;
	int flag =0;
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d", &num);
		if(s.empty()){
			for(int i=maxN+1;i<=num;i++)
			{
				s.push(i);
				c.push_back('+');
	//			printf("+\n");
			}
		}
		else{
			if(maxN<num)
			{
	//			printf("%d %d\n", maxN, num);
				for(int i=maxN+1;i<=num;i++)
				{
					s.push(i);
					c.push_back('+');
	//				printf("+\n");
				}
			}
		}
		maxN = max(num,maxN);
		if(s.top()==num)
		{
			//printf("-\n");
			c.push_back('-');
			s.pop();
			continue;
		}
		else{
			flag =1;
		}
	}
	if(flag)
		printf("NO\n");
	else
	{
		for(int i=0;i<c.size();i++)
			printf("%c\n", c[i]);
	}
	return 0;
}

