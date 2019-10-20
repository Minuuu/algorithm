#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int B = 251;
// MOD = 1e9+7;
unsigned long long hash_func(char *s, int len){
    unsigned long long hash = 0;
    for(int i=0;i<len;i++){
        hash  = (hash*B+s[i]);
    }
    return hash;
}
struct node{
    char str[15];
    bool operator <(const node a) const{
        if(strcmp(str,a.str)>=0)
            return false;
        return true;
    }
};
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        unsigned long long phone[10005][11]={0,};
        int lArr[10005]={0,};
        int n;
        scanf("%d", &n);
        int min = 0x3f3f3f3f;
        int idx = 0;
        vector<node> v;
        for(int i=0;i<n;i++){
            node n;
            scanf("%s", n.str);
            v.push_back(n);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            int len = strlen(v[i].str);
            lArr[i] = len;
            phone[i][0] = v[i].str[0];
            for(int j=1;j<len;j++){
                phone[i][j] = phone[i][j-1]*B+v[i].str[j];
            }
        }
        int flag =0;
        for(int i=0;i<n;i++){
            unsigned long long hash = phone[i][lArr[i]-1];
            for(int j=i+1;j<n;j++){
                if(hash==phone[j][lArr[i]-1]){
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag){
            printf("NO\n");
        }
        else
            printf("YES\n");
    }
    return 0;
}