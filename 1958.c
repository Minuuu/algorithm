#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[105][105][105];
char s1[105], s2[105], s3[105];
int main()
{
    scanf("%s %s %s", s1+1,s2+1,s3+1);
    int len1 = strlen(s1+1);
    int len2 = strlen(s2+1);
    int len3 = strlen(s3+1);
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
       {
           for(int k=1;k<=len3;k++)
           {
               if(s1[i]==s2[j]&&s2[j]==s3[k]){
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1;
        }
                else{
                    dp[i][j][k] = max(dp[i][j][k-1],max(dp[i-1][j][k],dp[i][j-1][k]));
                }
            }
        }
    }
    printf("%d\n", dp[len1][len2][len3]);
    return 0;
}