#include<stdio.h>
#include<string.h>
typedef unsigned long long ull;
ull save[10000][501];
int B = 251;
ull hash_f(char *s, int len){
    ull hash = 0;
    for(int i=0;i<len;i++){
        hash = (hash*B+s[i]);
    }
    return hash;
}
int main()
{
    int n,m;
    int ans = 0;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        char str[501];
        scanf("%s", str);
        int len = strlen(str);
        save[i][0] = str[0];
        for(int j=1;j<len;j++){
            save[i][j] = save[i][j-1]*B+str[j];
        }
    }
    for(int i=0;i<m;i++){
        char chk[501];
        scanf("%s", chk);
        int len = strlen(chk);
        ull hash = hash_f(chk,len);
        for(int j=0;j<n;j++){
            if(save[j][len-1]==hash){
                ans++;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}