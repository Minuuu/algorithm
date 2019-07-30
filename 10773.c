#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d", &num);
		if(num==0)
			s.pop();
		else{
			s.push(num);
		}
	}
	int sum=0;
	while(!s.empty())
	{
		sum+=s.top();
		s.pop();
	}
	printf("%d\n", sum);
	return 0;
}
