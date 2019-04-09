#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int N,M,K,A,B,T;

int a[10];//apply
int b[10];//repair
int va[10];
int vb[10];

int ta[10];
int tb[10];

int k[1001];//time & index= user num
int vk[1001];//time & index= user num
priority_queue<int,vector<int>,greater<int>> pq;
queue<int> q;
vector<int> useA;
vector<int> useB;
void solve(int time)
{
	for(int i=1;i<=N;i++)
	{
		if(va[i]!=0){
			ta[i]++;
		}
		if(ta[i]==a[i])
		{
			q.push(va[i]);
			va[i]=0;
			ta[i]=0;
		}
	}
	while(!pq.empty())
	{
		int num = pq.top();
		int flag=0;
		for(int i=1;i<=N;i++)
		{
			if(va[i]==0){
				va[i]=num;
				flag=1;
				if(i==A)
					useA.push_back(num);
				pq.pop();
				break;
			}
		}
		if(!flag){
			break;
		}
	}
	for(int i=1;i<=M;i++)
	{
		if(vb[i]!=0){
			tb[i]++;
		}
		if(tb[i]==b[i])
		{
			vb[i]=0;
			tb[i]=0;
		}
	}
	while(!q.empty())
	{
		int num = q.front();
		int flag=0;
		for(int i=1;i<=M;i++)
		{
			if(vb[i]==0){
				vk[num]=1;
				vb[i]=num;
				flag=1;
				if(i==B)
					useB.push_back(num);
				q.pop();
				break;
			}
		}
		if(!flag){
			break;
		}
	}
}
int main()
{
	scanf("%d", &T);
	for(int z=1;z<=T;z++)
	{
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		int num;
		memset(a,0,sizeof(a));
		memset(va,0,sizeof(a));
		memset(b,0,sizeof(a));
		memset(vb,0,sizeof(a));
		memset(ta,0,sizeof(a));
		memset(tb,0,sizeof(a));
		memset(k,0,sizeof(k));
		memset(vk,0,sizeof(vk));
		for(int i=1;i<=N;i++)
		{
			scanf("%d", &a[i]);
		}
		for(int i=1;i<=M;i++)
		{
			scanf("%d", &b[i]);
		}
		for(int i=1;i<=K;i++)
		{
			scanf("%d", &k[i]);
		}
		int time=0;
		while(1)
		{
			for(int i=1;i<=K;i++)
			{
				if(k[i]==time)
					pq.push(i);
			}
			solve(time);
			int flag=0;
			for(int i=1;i<=K;i++)
			{
				if(vk[i]==0)
				{
					flag=1;
					break;
				}
			}
			if(!flag){
				int sum=0;
				for(int i=0;i<useA.size();i++)
				{
					for(int j=0;j<useB.size();j++)
					{
						if(useA[i]==useB[j])
							sum+=useA[i];
					}
				}
				if(sum==0)
					sum=-1;
				printf("#%d %d\n", z,sum);
				break;
			}
			if(0){
				for(int i=1;i<=K;i++)
					printf("%d ", vk[i]);
				printf("\n");

				break;
			}
			time++;
		}
		useA.clear();
		useB.clear();
	}
	return 0;
}
