#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
	vector<pair<int,string>> v;
	for(int i=0;i<words.size();i++)
	{
		v.push_back({words[i].length(),words[i]});
	}
	sort(v.begin(),v.end());



    for(int i=0;i<queries.size();i++) {
        int cnt = 0;
        int len_tmp = queries[i].length();
        int start = 0, end = len_tmp - 1;
		string str = queries[i];
		if(str[0]=='?')
		{
			for(int j=0;j<str.length();j++)
			{
				if(str[j]!='?')
				{
					start = j;
					break;
				}
			}

		}
		else
		{
			for(int j=0;j<str.length();j++)
			{
				if(str[j]=='?')
				{
					end = j-1;
					break;
				}
			}
		}
		for(int j=0;j<v.size();j++)
		{
			string w = v[j].second;
			if(v[j].first == len_tmp)
			{
				int flag = 0;
				for(int k=start;k<=end;k++)
				{
					if(w[k]!=str[k]){
						flag = 1;
						break;
					}
				}
				if(flag==0)
					cnt++;
			}
		}
		answer.push_back(cnt);
    }

    return answer;
}

int main()
{
	vector<string> s,t;
	for(int i=0;i<6;i++)
	{
		string str;
		cin>>str;
		s.push_back(str);
	}
	for(int i=0;i<5;i++)
	{
		string str;
		cin>>str;
		t.push_back(str);
	}
	solution(s,t);
}
