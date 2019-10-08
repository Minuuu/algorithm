#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    int ans = min(n/2,m);
    ans = min(ans,(n+m-k)/3);
    printf("%d\n", ans);
    return 0;
}