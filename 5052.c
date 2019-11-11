#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
char arr[10001][11];
struct Node{
    Node *next[10];
    bool actual; //있었던건지 아닌지 판단
};
struct Node root;
void add(char *s){
    Node *cur = &root;
    for(int i=0;s[i];i++){
        if(cur->next[s[i]-'0']==NULL){
            cur->next[s[i]-'0']=new Node();
        }
        cur = cur->next[s[i]-'0'];
    }
    cur->actual = 1;
}
bool Find(char *s){
    Node *cur = &root;
    for(int i=0;s[i];i++){
        if(cur->actual==1){
            return true;
        }
        if(cur->next[s[i]-'0']==NULL)
            return false;
        cur = cur->next[s[i]-'0'];
    }
    return false;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        struct Node no={0,};
        root = no;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%s", arr[i]);
            add(arr[i]);
        }
        
        int flag = 0;
        for(int i=0;i<n;i++){
            if(Find(arr[i])==1){
                flag = 1;
                break;
            }
        }
        if(flag==1)
            printf("NO\n");
        else
            printf("YES\n");
        
    }

    return 0;
}