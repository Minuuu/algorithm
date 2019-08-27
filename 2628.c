#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int w,h;
	scanf("%d %d", &w, &h);
	int n;
	vector<int> v1;
	vector<int> v2;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		if(a==0)
			v1.push_back(b);
		else
			v2.push_back(b);
	}
	v1.push_back(0);
	v1.push_back(h);
	v2.push_back(0);
	v2.push_back(w);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	
	int ans = 0;
	for(int i=1;i<v1.size();i++)
	{
		int y = v1[i]-v1[i-1];
		for(int j=1;j<v2.size();j++)
		{
			int x = v2[j]-v2[j-1];
			ans = max(x*y,ans);
		}
	}
	printf("%d\n", ans);
	return 0;
}
