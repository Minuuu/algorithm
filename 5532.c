#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int L,A,B,C,D;
	cin>>L>>A>>B>>C>>D;
	int a1 = A/C;
	int a2 = A%C;
	
	int b1 = B/D;
	int b2 = B%D;

	if(a2!=0)
		a1++;
	if(b2!=0)
		b1++;

	cout<<L-max(a1,b1);

	return 0;
}
