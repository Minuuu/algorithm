#include<stdio.h>
#include<algorithm>
using namespace std;
char str[55][55];
int n;
int check()
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int cnt = 1;
		for(int j=0;j<n-1;j++)
		{
			if(str[i][j]==str[i][j+1]){
				cnt++;
			}
			else{
				ans = max(ans,cnt);
				cnt= 1;
			}
			ans= max(ans,cnt);
		}
	}
	return ans;
}
int check1()
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int cnt=1;
		int flag=0;
		for(int j=0;j<n-1;j++)
		{
			if(str[j][i]==str[j+1][i]){
				cnt++;
			}
			else
			{
				ans = max(ans,cnt);
				cnt=1;
			}
		}
		ans = max(ans,cnt);
	}
	return ans;
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf(" %c", &str[i][j]);
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(str[i][j]!=str[i][j+1])
			{
				swap(str[i][j],str[i][j+1]);
				int tmp = check();
				int tmp1 = check1();
				tmp = max(tmp,tmp1);
	//			printf("%d\n", tmp);
				ans = max(tmp,ans);
				swap(str[i][j],str[i][j+1]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(str[j][i]!=str[j+1][i])
			{
				swap(str[j][i],str[j+1][i]);
				int tmp = check();
				int tmp1 = check1();
				//printf("%c %c %d\n", str[j][i], str[j+1][i],tmp);
				tmp = max(tmp,tmp1);
				ans = max(tmp,ans);
				swap(str[j][i], str[j+1][i]);
			}
		}
		//printf("-------\n");
	}
	if(ans==0)
		ans = n;
	printf("%d\n", ans);
	return 0;
}
