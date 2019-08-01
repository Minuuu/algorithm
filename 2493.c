#include<stdio.h>
#include<stack>
using namespace std;
stack<pair<int,int> > s;
int main()
{
	int n,num;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &num);
		int cnt=1;
		while(!s.empty())
		{
			if(s.top().first<num)
			{
				s.pop();
			}
			else{
				cnt=s.top().second;
				break;
			}
		}
		if(s.empty())
			printf("0 ");
		else
			printf("%d ", cnt+1);
		s.push(make_pair(num,i));
	}
	return 0;
}
