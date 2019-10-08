#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int check(int n, string s) {
    string ret = "";
    vector<string> v;
    for(int i=0;i<s.length();i+=n) {
        v.push_back(s.substr(i, n));
    }
    v.push_back("");
    int cnt = 1;
    for(int i=1;i<v.size();i++) {
        if(v[i].compare(v[i-1]) == 0) 
			cnt++;
        else {
            if(cnt > 1) {
                ret.append(to_string(cnt));
                ret.append(v[i-1]);
            }
            else
                ret.append(v[i-1]);
			cnt = 1;
        }
    }
    return ret.length();
}
int solution(string s) {
    int answer = s.length();
    for(int i=1;i<=s.length()/2;i++) {
        int tmp = check(i, s);
		answer = min(answer, tmp);
    }
    return answer;
}

int main()
{
	string s;
	cin>>s;
	cout<<solution(s)<<endl;;
	return 0;
}
