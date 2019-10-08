#include<stdio.h>
#include<vector>
vector<pair<int,int>> v[26];
int main()
{
    int N,L,E;
    scanf("%d %d", &N, &L);
    scanf("%d", &E);
    for(int i=0;i<E;i++){
        char a,b;
        int d;
        scanf(" %c %c %d", a,b,d);
        v[b-'A'].push_back({a-'A',d});
        
    }
    return 0;
}