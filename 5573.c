#include<stdio.h>
int dp[1005][1005];
int map[1005][1005];
int main()
{
	int h,w,n;
	scanf("%d %d %d", &h,&w,&n);
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			scanf("%d", &map[i][j]);
	
	dp[1][1]=n;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(dp[i][j]!=0){
				dp[i+1][j] += dp[i][j]/2;
				dp[i][j+1] += dp[i][j]/2;
				if(dp[i][j]%2!=0){
					if(map[i][j]==1)
						dp[i][j+1]++;
					else
						dp[i+1][j]++;
				}
				else{
					if(map[i][j])
						map[i][j]=0;
					else
						map[i][j]=1;
				}
			}
		}
	}
	int x=1, y=1;
	while(1)
	{
		if(x>h||y>w)
			break;
		if(map[x][y])
			y++;
		else
			x++;
	}
	printf("%d %d\n", x,y);


	return 0;
}
