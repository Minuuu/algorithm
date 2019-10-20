#include<stdio.h>
void solve(int a, int b, int cnt)
{
    if(!cnt) return;
    solve(a,6-a-b,cnt-1);
    printf("%d %d\n", a,b);
    solve(6-a-b,b,cnt-1);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (1<<n)-1);
    solve(1,3,n);
    return 0;
}