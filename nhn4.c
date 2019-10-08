#include<stdio.h>
#include<vector>

int main()
{
    int N,L,E;
    scanf("%d %d", &N, &L);
    scanf("%d", &E);
    for(int i=0;i<E;i++){
        char a,b;
        int d;
        scanf(" %c %c %d", a,b,d);
        v[a-'A'].push_back({b-'A',d});
    }
    return 0;
}