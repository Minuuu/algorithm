#include<iostream>
#include<map>
using namespace std;
map<string, int> m;
map<string,int> ans;
int main(){
    int N,M;
    cin>>N>>M;
    string str;
    for(int i=0;i<N;i++){
        cin>>str;
        m.insert({str,1});
    }
    for(int i=0;i<M;i++){
        cin>>str;
        if(m.count(str)!=0){
            ans.insert({str,1});
        }
    }
    map<string,int>::iterator i;
    cout<<ans.size()<<'\n';
    for(i=ans.begin();i!=ans.end();i++)
        cout<<i->first<<'\n';
    return 0;
}