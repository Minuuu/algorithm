#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int visit[101];
int save[101];
queue<int> q[101];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1,num;i<=n;i++){
        char str[10];
        scanf("%s", str);
        if(!strcmp(str,"enqueue")){
            scanf("%d", &num);
            q[num].push(i);
        }
        else if(!strcmp(str,"dequeue")){
            int size = 0;
            for(int i=1;i<=100;i++){
                size = max(size,(int)q[i].size());
            }
            if(size==0)
            {
                printf("-1\n");
                continue;
            }
            int t = 987654321;
            int ans = -1;
            for(int i=1;i<=100;i++){
                if((int)q[i].size()==size){
                    if(t>q[i].front()){
                        t = q[i].front();
                        ans = i;
                    }
                }
            }
            q[i].pop();
            printf("%d", ans);
            
        }
    }
    return 0;
}