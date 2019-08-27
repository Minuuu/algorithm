#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n;
int ttime[501];
int chk[501];
vector<int> v[501];
queue<int> q;
int in[501];
int main()
{
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		int num;
		scanf("%d", &num);
		ttime[i] = num;
		while(1)
		{
			int num1;
			scanf("%d", &num1);
			if(num1==-1)
				break;
			v[num1].push_back(i);
			in[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
			q.push(i);
		chk[i] = ttime[i];
	}
	while(!q.empty())
	{
		int num = q.front();
		q.pop();
		for(int i=0;i<v[num].size();i++)
		{
			int next = v[num][i];
			chk[next] = max(chk[next],chk[num]+ttime[next]);
			in[next]--;
			if(in[next]==0)
				q.push(next);
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d\n", chk[i]);
	return 0;
}
