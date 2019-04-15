#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main(){
    
    string A,B;
    cin>>A>>B;
    
    int ans=50; //A와 B의 문자가 모두 다른 경우
    
    for(int dist=0;dist<=B.length()-A.length();dist++){
        
        int cnt=0;
        for(int i=0;i<A.length();i++){
            if(A[i]!=B[i+dist])
                cnt++;
        }
        
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
    
    return 0;
}