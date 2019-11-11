#include<stdio.h>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
int V,E;
vector<pair<int,int>> v[10001]; //prim vector
vector<pair<int,pair<int,int>>> v1; //kruskal vector
int p[10001];
int prim()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    bool visit[10001]={0,};
    int ans = 0;
    while(!pq.empty()){
        int w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visit[cur]==0){
            visit[cur] = 1;
            ans+=w;
            for(int i=0;i<v[cur].size();i++){
                if(!visit[v[cur][i].second]){
                    pq.push({v[cur][i]});
                }
            }
        }
    }
    return ans;
}
int Find(int num){
    if(p[num]==num) return num;
    return p[num] = Find(p[num]);
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    p[a] = b;
}

int main()
{
    scanf("%d %d", &V, &E);
    for(int i=0;i<E;i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({c,b});
        v[b].push_back({c,a});
        v1.push_back({c,{a,b}});
    }
    sort(v1.begin(),v1.end());
    int ans = 0;
    for(int i=1;i<=10000;i++)
        p[i] = i;
    for(int i=0;i<v1.size();i++){
        if(Find(v1[i].second.first)!=Find(v1[i].second.second)){
            Union(v1[i].second.first,v1[i].second.second);
            ans+=v1[i].first;
        }
    }
    printf("%d\n", ans);
    //printf("%d\n", prim());
    return 0;
}