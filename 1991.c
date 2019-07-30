#include<stdio.h>
#include<vector>
using namespace std;
vector<pair<char, char>> v[26];
void predorder(char c)
{
	printf("%c", c);
	if (v[c - 'A'][0].first != '.'|| v[c - 'A'][0].second != '.')
	{
		//printf("%c", v[c - 'A'][0].first);
		if(v[c-'A'][0].first!='.')
			predorder(v[c - 'A'][0].first);
		if(v[c - 'A'][0].second != '.')
			predorder(v[c - 'A'][0].second);
	}
}
void inorder(char c)
{
	if (v[c - 'A'][0].first != '.')
	{
		inorder(v[c - 'A'][0].first);
	}
	printf("%c", c);
	if (v[c - 'A'][0].second != '.')
	{
		inorder(v[c - 'A'][0].second);
	}
}
void postorder(char c)
{
	if (v[c - 'A'][0].first != '.')
	{
		postorder(v[c - 'A'][0].first);
	}
	if (v[c - 'A'][0].second != '.')
	{
		postorder(v[c - 'A'][0].second);
	}
	printf("%c", c);
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		char a, b, c;
		scanf(" %c %c %c", &a, &b, &c);
		v[a - 'A'].push_back(make_pair(b, c));
	}
	predorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	
	return 0;
}
