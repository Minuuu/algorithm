#include<stdio.h>
int main()
{
    char chess[8][8];
    int ans = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            scanf(" %c", &chess[i][j]);
            if((i+j)%2==0&&chess[i][j]=='F'){
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}