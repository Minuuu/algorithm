#include<stdio.h>
#include<string.h>
//char str[10000][500];
unsigned long long hash_function(char s[501]){
    long long hash = 0;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        hash = (s[i]+hash*251);
    }
    return hash;
}
int main()
{
    int N,M;
    long long arr[100001]={0,};
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        char tmp[501];
        scanf("%s", tmp);
        unsigned long long hash = hash_function(tmp);
        //printf("%d\n", hash);
        arr[i] = hash;
    }
    int ans = 0;
    for(int i=0;i<M;i++){
        char tmp[501];
        scanf("%s", tmp);
        unsigned long long hash = hash_function(tmp);
        //printf("%d\n", hash);
        for(int j=0;j<N;j++){
            if(arr[j]==hash)
                ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}