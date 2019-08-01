#include<stdio.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		int first;
		vector<int> v;
		scanf("%d", &first);
		for(int j=2;j<9;j++){
			int num;
			scanf("%d", &num);
			v.push_back(num);
		}
		sort(v.begin(),v.end(),greater<int>());
		v.insert(v.begin()+3,first);
		printf("\n");
		for(int i=0;i<v.size();i++)
		{
			printf("%d", v[i]);
		}
		
	}
	return 0;
}
