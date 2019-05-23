#include<iostream>
using namespace std;

int main()
{
	int n,cnt=0;
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n;
	for(int j=0;j<n;j++)
	{
		int num;
		cin>>num;
		int flag=0;
		for(int i=2;i*i<=num;i++)
		{
			if(num%i==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0&&num!=1)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
