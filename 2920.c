#include<stdio.h>
int main()
{
	int arr[8];
	int flag=0;
	for(int i=0;i<8;i++)
		scanf("%d", &arr[i]);

	for(int i=0;i<7;i++)
	{
		if(arr[i]-arr[i+1]==-1)
			flag=1;
		else{
			flag=0;
			break;
		}
	}

	if(flag==0){
		for(int i=0;i<7;i++)
		{
			if(arr[i]-arr[i+1]==1)
				flag=2;
			else{
				flag=0;
				break;
			}
		}
	}

	if(flag==0)
		printf("mixed");
	else if(flag==1)
		printf("ascending");
	else if(flag==2)
		printf("descending");


	return 0;
}
