#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n,m;
	int mm=987654321;
	int ans=-1;
	vector<int> v;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	vector<int> v1;
	for(int i=1;i<=3;i++)
		v1.push_back(0);
	for(int i=1;i<=n-3;i++)
		v1.push_back(1);
	do{
		int sum=0;
		for(int i=0;i<v1.size();i++)
		{
			if(v1[i]==0){
				sum+=v[i];
			}
		}
		if(m>=sum && m-sum<mm){
			mm=m-sum;
			ans=sum;
		}
	}while(next_permutation(v1.begin(),v1.end()));
	printf("%d\n", ans);
	return 0;
}
