#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int arr[1000];
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", arr+i);
    }
    sort(arr,arr+n);
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=(n-i)*arr[i];
    }
    printf("%d\n", sum);
    
    return 0;
}