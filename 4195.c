#include<stdio.h>
#include<string>
#include<map>
using namespace std;
int parent[200001];
int cc[200001];
int find(int num)
{
	if(parent[num]==num)
		return num;
	return parent[num] = find(parent[num]);
}
void Union(int a, int b)
{
	int ra = find(a);
	int rb = find(b);
	if(ra!=rb)
	{
		parent[ra]=rb;
		cc[rb] += cc[ra];
		cc[ra]=1;
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int f;
		scanf("%d", &f);
		map<string, int> m;
		int idx=0;
		char in1[21], in2[21];
		for(int i=0;i<2*f;i++)
		{
			parent[i]=i;
			cc[i] = 1;
		}
		for(int i=0;i<f;i++)
		{
			scanf("%s %s", in1, in2);
			if(m.count(in1)==0)
				m[in1]=idx++;
			if(m.count(in2)==0)
				m[in2]=idx++;
			Union(m[in1],m[in2]);
			printf("%d\n", cc[parent[m[in2]]]);
		}
	}

	



	return 0;
}
