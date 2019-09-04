#include<stdio.h>
#include<queue>
#include<stdlib.h>
#include<functional>
using namespace std;
//priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
struct node{
	int abs_num;
	int num;
	bool operator <(const node &o)const{
		if(abs_num==o.abs_num)
			return num>o.num;
		return abs_num>o.abs_num;
	};
};
priority_queue<struct node> q;
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d", &num);
		if(num==0)
		{
			if(!q.empty())
			{
				printf("%d\n", q.top().num);
				q.pop();
			}
			else
				printf("0\n");
		}
		else
			q.push({abs(num),num});
	}
	return 0;
}
