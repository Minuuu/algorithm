#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
bool bs(int start, int end,int ans)
{
	while(end>=start)
	{
		if(v[(start+end)/2]==ans)
			return true;
		else if(v[(start+end)/2]>ans)
			return bs(start,(start+end)/2-1,ans);
		else if(v[(start+end)/2]<ans)
			return bs((start+end)/2+1,end,ans);
	}
	return false;
}
int main()
{
	int n,m,num;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	scanf("%d", &m);
	for(int i=0;i<m;i++)
	{
		int flag=0;
		scanf("%d", &num);
//		printf("%d\n", binary_search(v.begin(),v.end(),num));
		printf("%d\n", bs(0,v.size(),num));
	}
	return 0;
}
