#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v[51];

int cnt = 0;
int dfs(int idx){
    if(v[idx].size()==0){
        cnt++;
        return 1;
    }
    int ret = 0;
    int flag = 0;
    for(int i=0;i<v[idx].size();i++){
        if(v[idx][i]!=-1){
            ret += dfs(v[idx][i]);
            v[idx][i] = -1;
            flag = 1;
        }
    }
    if(!flag)
        return 1;
    return ret;
}
int main()
{
    int n;
    int root ;
    scanf("%d", &n);
    int par[51];
    for(int i=0;i<n;i++){
        scanf("%d", par+i);
        if(par[i]==-1){
            root = i;
        }
        else
            v[par[i]].push_back(i);
    }
    int del;
    scanf("%d", &del);
    int p = par[del];
    if(p==-1)
    {
        printf("0");
        return 0;
    }
    for(int i=0;i<v[p].size();i++){
        if(v[p][i]==del){
            v[p][i] = -1;
            break;
        }
    }
    dfs(del);
    printf("%d\n", dfs(root));
    
    return 0;
}