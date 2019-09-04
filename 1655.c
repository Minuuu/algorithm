#include<stdio.h>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d", &num);
		if(maxq.empty()&&minq.empty())
			maxq.push(num);
		else if(maxq.top()<num)
			minq.push(num);
		else
			maxq.push(num);

		if(maxq.size()>minq.size()+1)
		{
			num = maxq.top();
			maxq.pop();
			minq.push(num);
		}
		else if(minq.size()>maxq.size())
		{
			num = minq.top();
			minq.pop();
			maxq.push(num);
		}
		printf("%d\n", maxq.top());
	}
}
