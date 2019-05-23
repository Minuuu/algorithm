#include<iostream>
#include<climits>
#include<queue>
using namespace std;

vector<pair<int,int>> v[20001];
vector<int> dij(int start, int V)
{
	vector<int> d(V,INT_MAX);
	d[start]=0;
	//pq = {w,vertex}
	priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,start});
	while(!pq.empty())
	{
		int curW = pq.top().first;
		int curV = pq.top().second;
		pq.pop();

		if(d[curV]<curW)
			continue;

		int num = v[curV].size();
		for(int i=0;i<num;i++){
			int vertex = v[curV][i].first;
//			int weight = curW+v[curV][i].second;
			if(d[vertex]>curW+v[curV][i].second){
				d[vertex]=weight;
				pq.push({curW+v[cirV][i].second,vertex});
			}
		}
	}
	return d;
}
int main()
{
	int V,E,K;
	cin>>V>>E;
	cin>>K;
	for(int i=0;i<E;i++)
	{
		int from,to,w;
		cin>>from>>to>>w;
		v[u].push_back({to,w});
	}
	vector<int> res = dij(K,V+1);
	for(int i=1;i<V+1;i++){
		if(res[i]==INT_MAX)
			printf("INF\n");
		else
			printf("%d\n", res[i]);
	}
			
	return 0;
}
