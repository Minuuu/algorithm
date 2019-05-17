#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d %d", &x, &y);
	int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int day=y-1;
	for(int i=0;i<x-1;i++)
		day+=months[i];

	switch(day%7)
	{
		case 0:
			printf("MON\n");
			break;
		case 1:
			printf("TUE\n");
			break;
		case 2:
			printf("WED\n");
			break;
		case 3:
			printf("THU\n");
			break;
		case 4:
			printf("FRI\n");
			break;
		case 5:
			printf("SAT\n");
			break;
		case 6:
			printf("SUN\n");
			break;
	}
	return 0;
}
