#include<stdio.h>
int savePr[1000001];
int main()
{
	for (int i = 1; i <= 1000000; i++)
		savePr[i] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		for (int j = i+i; j <= 1000000; j += i)
			if (savePr[j] == 1) {
				savePr[j] = 0;
			}
	}
	while (1)
	{
		int input,i,flag=0;
		scanf("%d", &input);
		if (input == 0)
			break;
		for (i = 3; i <= input / 2; i+=2) {
			if (savePr[i] == 1  && savePr[input - i] == 1) {
				flag = 1;
				break;
			}
				
		}
		if (flag)
			printf("%d = %d + %d\n", input, i, input - i);
		else
			printf("Goldbach's conjecture is wrong.\n");

	}
	return 0;
}
