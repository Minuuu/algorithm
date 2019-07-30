#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v;
int pp[1000001];
int main()
{
	int P, K;
	char str[101];
	
	scanf("%s %d", &str, &K);
	for (int i = 2; i < K; i++)
		pp[i] = 1;
	for (int i = 2; i < K; i++) {
		for (int j = i + i; j < K; j += i) {
			if (pp[j] == 1)
			{
				pp[j] = 0;
			}
		}
	}
	for (int i = 2; i < K; i++)
		if (pp[i] == 1)
			v.push_back(i);
	
	for (int j = 0; j < v.size(); j++) {
		int res = 1;
		int prev = 0;
		res = str[0] - '0';
		for (int i = 0; i < strlen(str); i++)
		{
			int num = str[i] - '0';
			res = prev+num;
			res = res%v[j];
			prev = res * 10;
			if (i == strlen(str) - 1 && res == 0)
			{
				printf("BAD %d\n", v[j]);
				return 0;
			}	
		}

	}

	printf("GOOD\n");

	return 0;
}
