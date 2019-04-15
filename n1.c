#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int solution(vector<int> &T)
{
	int tmp=T[0];
	int maxT=T[0];
	int ret;
	for(int i=0;i<T.size();i++)
	{
		if(tmp>=T[i])
		{
			ret=i+1;
			tmp=maxT:
		}
		if(maxT<T[i])
		{
			maxT=T[i];
		}
	}
	return 0;
}
int main()
{
	int N;
	int num;
	vector<int> v;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>num;
		v.push_back(num);
	}
	
	solution(v);


	return 0;
}
