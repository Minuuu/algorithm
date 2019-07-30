#include<stdio.h>
long long arr[100001];
long long tr[400001];
long long mt(long long left, long long right, long long idx)
{
	if (left == right) {
		return tr[idx] = arr[left];
	}
	return tr[idx] += mt(left, (left + right) / 2, idx * 2) + mt((left + right) / 2 + 1, right, idx * 2 + 1);
}
void upd(long long left, long long right, long long idx, long long diff, long long change)
{
	if (left > change || change > right) {
		return;
	}
	tr[idx] += diff;
	if (left != right) {
		long long mid = (left + right) / 2;
		upd(left, mid, idx * 2, diff,change);
		upd(mid+1, right, idx * 2 + 1,diff,change);
	}
}

long long query(long long left, long long right, long long x, long long y, long long idx)
{
	if (y<left || x>right)
		return 0;
	else if (x <= left&&right <= y)
	{
		return tr[idx];
	}
	else {
		long long mid = (left + right) / 2;
		long long r1 = query(left, mid, x, y, 2 * idx);
		long long r2 = query(mid + 1, right, x, y, 2 * idx + 1);
		return (r1 + r2);
	}
}
int main()
{
	int n,q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%lld", arr + i);

	mt(1,n,1);
	for (int i = 0; i < q; i++)
	{
		long long x, y, a, b;
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if (x > y)
		{
			long long tmp = x;
			x = y;
			y = tmp;
		}
		printf("%lld\n", query(1, n, x, y, 1));
		upd(1, n, 1, b - arr[a], a);
		arr[a] = b;
	}
	return 0;
}
