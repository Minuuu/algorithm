#include<stdio.h>
int tab[101];
int main()
{
    int n,k,arr[101],ans=0;;
    scanf("%d %d", &n, &k);
    for(int i=0;i<k;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<k;i++){
        int num = arr[i];
        int flag = 0;
        for(int j=0;j<n;j++){
            if(tab[j]==num){
                flag = 1;
                break;
            }
        }
        if(flag)
            continue;
        for(int j=0;j<n;j++){
            if(tab[j]==0)
            {
                tab[j] = num;
                flag = 1;
                break;
            }   
        }
        if(flag)
            continue;
        int idx = 0, maxidx = -1;
        for(int j=0;j<n;j++){
            int tmp = 0;
            for(int x = i+1;x<k;x++){
                if(tab[j]==arr[x])
                    break;
                tmp++;
            }
            if(tmp>maxidx){
                idx = j;
                maxidx = tmp;
            }
        }
        ans++;
        tab[idx] = arr[i];
    }
    printf("%d\n", ans);
    return 0;
}