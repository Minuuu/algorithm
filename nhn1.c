#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string,int> m;
vector<int> v;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        if(m.count(str)==0){
            m.insert({str,1});
        }
        else{
            m[str]++;
        }
    }  
    map<string,int>::iterator i;
    int sum = 0;
    for(i=m.begin();i!=m.end();i++){
        v.push_back(i->second);
        sum+=i->second;
    }
    sort(v.begin(),v.end());
    int flag = 0;
    for(int i=v.size()-1;i>=1;i--){
        if(v[i-1]!=v[i]){
            if(i!=1)
            {
                flag = 1;
                break;
            }
        }
    } 
    if(flag){
        cout<<'N'<<'\n';
        cout<<sum<<'\n';
        cout<<m.size()<<'\n';
    }
    else{
        cout<<'Y'<<'\n';
        cout<<v[v.size()-1]*v.size()<<'\n';
        cout<<m.size()<<'\n';
    }
    return 0;
}