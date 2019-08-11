#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int prime[10000];
int solve(int a, int b)
{
	queue<int> q;
	q.push(a);
	int cnt=0;
	int visit[10000]={0,};
	visit[a]=1;
	while(!q.empty())
	{
		int size = q.size();
		cnt++;
		for(int s=0;s<size;s++){
			int num = q.front();
			if(num==b){
				return cnt;
			}
			q.pop();
			int arr[4];
			for(int j=0;j<4;j++){
				for(int i=0;i<=9;i++)
				{
					arr[0] = num/1000;
					arr[1] = (num%1000)/100;
					arr[2] = ((num%1000)%100)/10;
					arr[3] = num%10;

					if(arr[j]==i)
						continue;
					if(j==0||j==3)
						if(i==0)
							continue;
					arr[j] = i;
					int num = arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];
					if(prime[num]==0&&visit[num]==0){
						q.push(num);
						visit[num]=1;
					}
				}
			}
		}
	}
	return -1;
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int i=2;i<10000;i++)
	{
		for(int j=i+i;j<10000;j+=i)
			if(prime[j]==0)
				prime[j]=1;
	}
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int ret = solve(a,b);
		if(ret==-1)
			cout<<"Impossible"<<'\n';
		else
			cout<<ret-1<<'\n';
	}
	return 0;
}
