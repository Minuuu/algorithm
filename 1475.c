#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int visit[10];
int main()
{
    char str[10];
    scanf("%s", str);
    for(int i=0;i<strlen(str);i++){
        int num = str[i]-'0';
        if(num==9){
            if(visit[num]==visit[6]){
                visit[num]++;
            }
            else{
                if(visit[num]>visit[6])
                    visit[6]++;
                else{
                    visit[num]++;
                }
            }
        }
        else if(num==6){
            if(visit[num]==visit[9]){
                visit[num]++;
            }
            else{
                if(visit[num]>visit[9])
                    visit[9]++;
                else{
                    visit[num]++;
                }
            }
        }
        else
            visit[num]++;
    }
    printf("%d\n", *max_element(visit,visit+10));
    return 0;
}