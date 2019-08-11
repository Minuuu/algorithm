#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int N;
string str;
vector<pair<int,string>> v;
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>str;
		v.push_back({str.length(),str});
	}
	sort(v.begin(),v.end());
	vector<pair<int,string>>::iterator newend;
	newend = unique(v.begin(),v.end());
	v.erase(newend,v.end());
	for(int i=0;i<v.size();i++)
		cout<<v[i].second<<endl;
	return 0;
}
