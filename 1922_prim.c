#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int,int>> v[1001];
int prim()
{
    int ans = 0;
    bool visit[1001]={0,};
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visit[cur]==0){
            visit[cur] = 1;
            ans+=w;
            for(int i=0;i<v[cur].size();i++){
                if(visit[v[cur][i].second]==0){
                    pq.push({v[cur][i]});
                }
            }
        }
    }
    return ans;
}
int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    printf("%d\n",prim());
    return 0;
}