#include<stdio.h>
int N;
int map[101];
int op[4];
int min=1000000001;
int max=-1000000001;
void solve(int idx, int res, int plus, int minus, int mul, int div)
{
	if(plus==0&&minus==0&&mul==0&&div==0){
	//	printf("res: %d\n", res);
		if(res>max)
			max=res;
		if(res<min)
			min=res;
		return ;
	}
	if(plus!=0){
		int tmp = res + map[idx];
		solve(idx+1,tmp,plus-1,minus,mul,div);
	}
	if(minus!=0){
		int tmp = res - map[idx];
		solve(idx+1,tmp,plus,minus-1,mul,div);
	}
	if(mul!=0){
		int tmp = res*map[idx];
		solve(idx+1,tmp,plus,minus,mul-1,div);
	}
	if(div!=0){
		int tmp;
		if(res<0){
			tmp = -((-res)/map[idx]);
		}
		else
			tmp = res/map[idx];

		solve(idx+1,tmp,plus,minus,mul,div-1);
	}
}
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%d", &map[i]);
	for(int i=0;i<4;i++)
		scanf("%d", &op[i]);
	solve(2,map[1],op[0], op[1], op[2], op[3]);
	printf("%d\n", max);
	printf("%d\n", min);
	return 0;
}
