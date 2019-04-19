#include<iostream>
using namespace std;
int seq[20];
int main()
{
	int N,K;
	cin>>N>>K;
	for(int i=0;i<N-1;i++)
		scanf("%d,", &seq[i]);
	scanf("%d", &seq[N-1]);
	for(int i=0;i<K;i++)
	{
		for(int j=0;j<N-1;j++)
		{
			seq[j]=seq[j+1]-seq[j];
		}
		N--;
	}
	for(int i=0;i<N-1;i++)
		cout<<seq[i]<<',';
	cout<<seq[N-1];
		

	return 0;
}
