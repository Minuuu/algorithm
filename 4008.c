#include<stdio.h>
#include<string.h>
int T, N;
int op[4];
int input[12];
int max=-100000001;
int min=100000001;
void solve(int idx, int res, int plus, int minus, int mul, int div)
{
	if(plus==0&&minus==0&&mul==0&&div==0)
	{
		if(max<res)
			max=res;
		if(min>res)
			min=res;
		return ;
	}
	if(plus!=0)
	{
		int tmp = res+input[idx];
		solve(idx+1,tmp,plus-1,minus,mul,div);
	}
	if(minus!=0)
	{
		int tmp = res-input[idx];
		solve(idx+1,tmp,plus,minus-1,mul,div);
	}
	if(mul!=0)
	{
		int tmp = res*input[idx];
		solve(idx+1,tmp,plus,minus,mul-1,div);
	}
	if(div!=0)
	{
		int tmp = res/input[idx];
		solve(idx+1,tmp,plus,minus,mul,div-1);
	}
}
int main()
{
	scanf("%d", &T);
	for(int i=1;i<=T;i++)
	{
		max=-100000001;
		min=100000001;
		memset(input,0,sizeof(input));
		scanf("%d", &N);
		scanf("%d %d %d %d", &op[0], &op[1], &op[2], &op[3]);
		for(int i=0;i<N;i++)
			scanf("%d", &input[i]);
		solve(1,input[0],op[0],op[1],op[2],op[3]);
		printf("#%d %d\n", i,max-min);
	}
	return 0;
}
