#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
typedef struct{
	int x;
	int num;
} Node;
struct cmp{
	bool operator()(const Node &a, const Node &b)
	{
		return a.num<b.num;
	}
};
priority_queue<Node, vector<Node>, cmp> pq;
int main()
{
	pq.push({0,5});
	pq.push({0,3});
	pq.push({0,2});
	pq.push({0,4});
	while(!pq.empty())
	{
		int num = pq.top().num;
		printf("num: %d\n", num);
		pq.pop();
	}
	return 0;
}
