#include<stdio.h>
#include<map>
#include<iostream>
#include<vector>
#include<string>
int arr[11];
int visit[11];
using namespace std;
int n, k;
vector<int> v;
map<string, int> m;
void solve(int idx, int cnt)
{
	if (cnt == k)
	{
		string str = "";
		
		for (int i = 0; i < v.size(); i++) {
			string tmp = to_string(v[i]);
			str += tmp;
		}
	//	cout << str << endl;
		m.insert({ str,1 });
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == 0) {
			visit[i] = 1;
			v.push_back(arr[i]);
			solve(i, cnt + 1);
			v.pop_back();
			visit[i] = 0;
		}
	}

}
int main()
{

	scanf("%d", &n);
	scanf("%d", &k);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			v.push_back(arr[i]);
			solve(i, 1);
			v.pop_back();
			visit[i] = 0;
		}
	}
	
	printf("%d\n", m.size());
	return 0;
}
