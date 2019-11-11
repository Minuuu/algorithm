#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
int n,m;
vector<pii> v[100001];
int prim()
{
    priority_queue<pii,vector<pii>, greater<pii>> pq;
    bool visit[100001]={0,};
    int ans = 0;
    int max = -1;
    pq.push({0,1});
    while(!pq.empty()){
        int w = pq.top().first;
        int c = pq.top().second;
        pq.pop();
        if(visit[c]==0){
            ans+=w;
            visit[c] = 1;
            if(max<w)
                max = w;
            for(auto i : v[c]){
                if(visit[i.second]==0){
                    pq.push(i);
                }
            }
        }
    }
    return ans-max;
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    printf("%d\n", prim());
    return 0;
}