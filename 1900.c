#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    int a,b,idx;
    bool operator <(const node &o) const{
        return a+o.a*b > o.a+o.b*a;
    }
};
int main()
{
    int n;
    scanf("%d", &n);
    vector<node> v;
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d %d", &a, &b);
        v.push_back({a,b,i});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        printf("%d\n", v[i].idx);
    }
    return 0;
}