#include<iostream>
#include<stack>
using namespace std;
bool is_possible(string str)
{
	stack<char> s;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(')
		{
			s.push(str[i]);
		}
		else if(str[i]==')')
		{
			if(s.empty())
			{
				return false;
			}
			else{
				s.pop();
			}
		}
	}
	if(s.empty())
		return true;
	return false;
}
int check(string p)
{
	int l = 0;
	int r = 0;
	for(int i=0;i<p.length();i++)
	{
		if(p[i] == '(')
			l++;
		else
			r++;
		if(l==r)
		{
			return i+1;
		}
	}
	return -1;
}
string solution(string p)
{
	string ans = "";
	int idx = check(p);
	string l = "", r="";

	for(int i=0;i<idx;i++)
		l+=p[i];
	for(int j=idx;j<p.length();j++)
		r+=p[j];
	//cout<<"l: "<<l<<' '<<"r: "<<r<<endl;
	if(!is_possible(l))
	{
		ans += '(';
		if(!is_possible(r)&&!r.empty())
			ans += solution(r);
		else
			ans += r;
		ans += ')';
		//cout<<"ans: "<<ans<<endl;
		for(int i = 1; i<l.length()-1;i++)
		{
			if(l[i]=='(')
				ans += ')';
			else
				ans += '(';
		}
		//cout<<"AA: "<<ans<<endl;
	}
	else
	{
		ans+=l;
		if(!is_possible(r))
			ans += solution(r);
		else
			ans += r;
	}

	return ans;
}
int main()
{
	string p;
	cin>>p;
	cout<<solution(p)<<endl;;
	return 0;
}
