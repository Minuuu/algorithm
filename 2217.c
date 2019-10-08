#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n, arr[100001];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", arr+i);
    }
    sort(arr,arr+n);
    int ans = -1;
    for(int i=0;i<n;i++){
        ans = max(ans,arr[i]*(n-i));
    }
    printf("%d\n", ans);
    return 0;
}