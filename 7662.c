#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int k;
		bool visit[1000001] = {0,};
		priority_queue<pair<int, int >> maxq;
		priority_queue<pair<int,int >, vector<pair<int, int >>, greater<pair<int ,int >>> minq;
		scanf("%d", &k);
		for(int i=0;i<k;i++)
		{
			char c;
			int num;
			scanf(" %c", &c);
			if(c=='I')
			{
				scanf("%d", &num);
				maxq.push({num,i});
				minq.push({num,i});
				visit[i] = true;
			}
			else if(c=='D')
			{
				scanf("%d", &num);
				if(num==1)
				{
					while(!maxq.empty() &&!visit[maxq.top().second])
						maxq.pop();
					if(!maxq.empty())
					{
						visit[maxq.top().second] = false;
						maxq.pop();
					}
				}
				else
				{
					while(!minq.empty() && !visit[minq.top().second])
						minq.pop();
					if(!minq.empty())
					{
						visit[minq.top().second] = false;
						minq.pop();
					}
				}
			}
		}
		/*
		for(int i=0;i<k;i++)
			printf("%d ", visit[i]);
		printf("\n");
		*/
		while(!maxq.empty() && visit[maxq.top().second]==0)
			maxq.pop();
		while(!minq.empty() && visit[minq.top().second]==0)
			minq.pop();
		/*
		while(!maxq.empty())
		{
			printf("%d %d\n", maxq.top().first, maxq.top().second);
			maxq.pop();
		}
		printf("-----\n");
		while(!minq.empty())
		{
			printf("%d %d\n", minq.top().first, minq.top().second);
			minq.pop();
		}
		*/
	//	printf("%d %d\n", maxq.size(),minq.size());
		if(!minq.empty()&&!maxq.empty())
			printf("%d %d\n", maxq.top().first, minq.top().first);
		else
			printf("EMPTY\n");
			
	}
	return 0;
}
