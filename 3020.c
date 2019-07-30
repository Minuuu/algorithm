#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//v1= bottom v2 = top
vector<int> v1,v2;
int main()
{
	int n,h;
	scanf("%d %d", &n, &h);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d", &num);
		if(i%2==0)
			v1.push_back(num);
		else
			v2.push_back(h-num+1);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int i=0;i<v1.size();i++)
		printf("%d ", v1[i]);
	printf("\n");
	int ans=987654321;
	vector<int> v3;
	for(int i=1;i<=h;i++)
	{
		int cnt = lower_bound(v1.begin(),v1.end(),i)-v1.begin()+1;
		int cnt1 = upper_bound(v2.begin(),v2.end(),i)-v2.begin();
		int tot = n/2-cnt+1+cnt1;
		v3.push_back(tot);
		if(ans>tot)
		{
			ans=tot;
		}
	}
	printf("%d %d\n",ans, count(v3.begin(),v3.end(),ans));
	return 0;
}
