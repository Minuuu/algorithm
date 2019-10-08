#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
char str[1000005];
char comp[1000005];
#define MOD 1000000007
vector<int> ans;
long long hash_func(const char s[1000005], int len){
    long long hash=0;
    for(int i=0;i<len;i++){
        hash = (s[i]+hash*251)%MOD;
    }
    return hash;
}

int main()
{
    scanf("%[^\n]", str);
    getchar();
    scanf("%[^\n]", comp);

    int len = strlen(comp);
    int len1 = strlen(str);

    long long h = hash_func(comp, len);
    long long hash = hash_func(str, len);
    long long P = 1;
    
    
    for(int i = 0; i<len-1;i++)
        P = (P*251)%MOD;

    
    if(hash==h)
        ans.push_back(0);
    
    for(int i=1;i<=len1-len;i++){
        hash = (hash-((str[i-1]*P) % MOD) + MOD) % MOD;
        hash = (hash*251+str[i+len-1])%MOD;
        if(hash==h){
            ans.push_back(i);
        }
    }
    printf("%lu\n", ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%d ", ans[i] + 1);
    }
    return 0;
}