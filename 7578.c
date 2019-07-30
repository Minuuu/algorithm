#include<stdio.h>
int a[500005];
int b[1000005];
int seg[1000005 * 4];
int query(int left, int right, int node, int start, int end)
{
	if (start > right || end < left)
		return 0;
	if (start <= left&&right <= end) {
		return seg[node];
	}
	int mid = (left + right) / 2;
	return query(left, mid, node * 2, start, end)+query(mid+1,right,node*2+1,start,end);
}
void update(int left, int right, int node, int idx)
{
	if (!(left<=idx&&idx<=right))
		return;
	if (left == right)
	{
		seg[node] = 1;
		return;
	}
	int mid = (left + right) / 2;
	update(left, mid, 2 * node, idx);
	update(mid + 1, right, 2 * node + 1, idx);
	seg[node] = seg[2 * node] + seg[2 * node + 1];
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int j = 1; j <= n; j++)
	{
		int num;
		scanf("%d", &num);
		b[num] = j;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int ret = query(1, n, 1, b[a[i]], n);
		ans += ret;
		update(1, n, 1, b[a[i]]);
	}
	printf("%lld\n", ans);
	return 0;
}
