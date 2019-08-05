#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<char> v;
bool check(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		return true;
	return false;
}
int main()
{
	int L,C;
	scanf("%d %d", &L, &C);
	for(int i=0;i<C;i++)
	{
		char c;
		scanf(" %c", &c);
		v.push_back(c);
	}
	vector<int> tmp;
	for(int i=0;i<L;i++)
		tmp.push_back(1);
	for(int i=0;i<C-L;i++)
		tmp.push_back(0);

	sort(v.begin(),v.end());

	do{
		int flag=0;
		int cnt=0;
		int idx=0;
		vector<char> ans;
		for(int i=0;i<tmp.size();i++)
		{
			if(tmp[i]==1)
			{
	//			printf("%c",v[i]);
				if(check(v[i]))
					flag=1;
				else{
					cnt++;
				}
				ans.push_back(v[i]);
			}
		}
		if(cnt>=2&&flag)
		{
			for(int i=0;i<ans.size();i++)
			{
				printf("%c", ans[i]);
			}
			printf("\n");
		}
	}while(prev_permutation(tmp.begin(),tmp.end()));
	return 0;
}
