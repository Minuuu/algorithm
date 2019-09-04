#include<stdio.h>
#include<string>
#include<queue>
using namespace std;
int D(int num)
{
	return num*2%10000;
}
int S(int num)
{
	return num==0 ? 9999:num-1;
}
int L(int num)
{
	int idx = 0;
	int arr[5]={0,};
	while(num>0)
	{
		arr[idx++] = num%10;
		num/=10;
	}
	int tmp = arr[3];
	for(int i=3;i>0;i--)
		arr[i] = arr[i-1];
	arr[0] = tmp;
	int ret = 0;
	for(int i=3;i>=0;i--)
		ret = (arr[i]+ret)*10;
	return ret/10;
}
int R(int num)
{
	int idx = 0;
	int arr[5]={0,};
	while(num>0)
	{
		arr[idx++] = num%10;
		num/=10;
	}
	int tmp = arr[0];
	for(int i=0;i<4;i++)
		arr[i] = arr[i+1];
	arr[3] = tmp;
	int ret = 0;
	for(int i=3;i>=0;i--)
		ret = (arr[i]+ret)*10;
	return ret/10;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int a,b;
		int visit[10000]={0,};
		queue<pair<int, string>> q;
		scanf("%d %d", &a, &b);
		q.push({a,""});
		while(!q.empty())
		{
			int num = q.front().first;
			string str = q.front().second;
			if(num==b){
				printf("%s\n", str.c_str());
				break;
			}
			q.pop();
			int d = D(num);
			int s = S(num);
			//int l = L(num);
			//int r = R(num);
			int l  = num%1000*10+num/1000;
			int r = num%10*1000+num/10;
			if(!visit[d]){
				q.push({d,str+"D"});
				visit[d] = 1;
			}
			if(!visit[s]){
				q.push({s,str+"S"});
				visit[s] = 1;
			}
			if(!visit[l]){
				q.push({l,str+"L"});
				visit[l] = 1;
			}
			if(!visit[r]){
				q.push({r,str+"R"});
				visit[r] = 1;
			}
		}
	}
	return 0;
}
