#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef unsigned long long ull;
int B = 251;
#define MOD 1000000007
vector<pair<int,char>> v[500001];
ull P = 1;
int cnt = 0;
ull hash_f(string s, int len){
    ull hash = 0 ; 
    for(int i=0;i<len;i++){
        hash = (hash*B+s[i]);
    }
    return hash;
}
void solve(int idx, int len, string s, ull hash, ull ans){
    //cout<<"idx: "<<idx<<' '<<s<<' '<<hash<<'\n';
    if(hash == ans){
        //cout<<"HASH: "<<hash<<'\n';
        cnt++;
    }
    for(int i=0;i<v[idx].size();i++){
        
        unsigned long long h = hash;
        if(s.length()==len){
            string tmp = "";
            for(int i=1;i<s.length();i++){
                tmp+=s[i];
            }
            h = h-(s[0]*P);
            h = (h*B+v[idx][i].second);
            tmp+=v[idx][i].second;
            solve(v[idx][i].first, len, tmp, h, ans);
        }
        else{
            string s1(s);
            s1+=v[idx][i].second;
            h = (h*B+v[idx][i].second);
            solve(v[idx][i].first, len, s1, h, ans);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    
    for(int i=0, a, b;i<n-1;i++){
        char c;
        scanf("%d %d %c", &a, &b, &c);
        v[a].push_back({b,c});
    }
    string str ;
    cin>>str;
    int len = str.length();
    ull h = hash_f(str, len);
    
    for(int i=0;i<len-1;i++){
        P = (P*251);
    }
    //solve(v[idx][i].first, len, s+1, hash, ans);
    //cout<<P<<' '<<h<<endl;
    solve(1,len, "",0, h);
    cout<<cnt;
    return 0;
}