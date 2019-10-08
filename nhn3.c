#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    int n;
    char c;
    scanf("%d", &n);
    int idx = -1;
    vector<int> v(n,0);
    vector<vector<int>> fol(n);
    vector<int> candy(n,0);
    while(scanf(" %c", &c)!=EOF){
        idx++;
        int num;
        vector<int> chk(n,0);
        if(c=='K'){
            scanf("%d", &num);
            fol[idx].push_back(num);
        }
        else if(c=='A'){
            candy[idx]++;
            for(int i=0;i<fol[idx].size();i++){
                if(chk[fol[idx][i]==0]){
                    chk[fol[idx][i]] = 1;
                    candy[fol[idx][i]]++;
                }
                else{
                    break;
                }
            }
        }
        else if(c=='J'){
            
        }
        else if(c=='Q'){
            for(int i=0;i<n;i++){
               candy[i]++;
            }
        }
        
    }
    for(int i=0;i<n;i++)
        printf("%d", candy[i]);
    return 0;
}