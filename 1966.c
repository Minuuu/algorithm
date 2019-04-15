#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	int T,N,M;
	int digit[100];
	scanf("%d", &T);
	for(int t=1;t<=T;t++)
	{
		priority_queue<int, vector<int>, less<int>> pq;
		queue<pair<int,int>> q;
		scanf("%d %d", &N, &M);
		int num;
		for(int i=0;i<N;i++){
			scanf("%d", &digit[i]);
			q.push(make_pair(digit[i],i));
			pq.push(digit[i]);
		}
		int cnt=0;
		while(1)
		{
			int num = q.front().first;
			int idx = q.front().second;
			q.pop();
			if(num==pq.top()){
				int value = pq.top();
				pq.pop();
				cnt++;
				if(idx==M){
					break;
				}
			}
			else
				q.push(make_pair(num,idx));
		
		}
		printf("%d\n", cnt);


	}
	return 0;
}
