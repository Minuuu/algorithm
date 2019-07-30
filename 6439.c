#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct pos {
	long long x;
	long long y;
} Point;
vector<struct pos> v;

long long ccw(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
	return ax*by + bx*cy + cx*ay - ay*bx - by*cx - cy*ax;
}

bool solution(Point p1, Point p2, Point r1, Point r2)
{

	int cnt = 0;
	/*
	for(int i=0;i<v.size();i++)
		printf("%d %d\n", v[i].first, v[i].second);
	printf("\n");
	*/
	long long c1 = ccw(p1.x, p1.y, p2.x, p2.y, r1.x, r1.y);
	long long c2 = ccw(p1.x, p1.y, p2.x, p2.y, r2.x, r2.y);
	long long c3 = ccw(r1.x, r1.y, r2.x, r2.y, p1.x, p1.y);
	long long c4 = ccw(r1.x, r1.y, r2.x, r2.y, p2.x, p2.y);
	long long ab = c1*c2;
	long long cd = c3*c4;

	if (ab <= 0 && cd <= 0) {
		if (ab == 0 && cd == 0) {
			pair<long long, long long> a = { p1.x,p1.y };
			pair<long long, long long> b = { p2.x,p2.y };
			pair<long long, long long> c = { r1.x,r1.y };
			pair<long long, long long> d = { r2.x,r2.y };

			if (a > b)
				swap(a, b);
			if (c > d)
				swap(c, d);
			return c <= b&&a <= d;
		}
		
		
		return true;
	}
	return false;
	
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		
		Point p1, p2;
		long long rx1, ry1, rx2, ry2;
		v.clear();
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &p1.x, &p1.y, &p2.x, &p2.y, &rx1, &ry1, &rx2, &ry2);
		if (rx1 > rx2)
			swap(rx1, rx2);
		if (ry1 > ry2)
			swap(ry1, ry2);
		v.push_back({ rx1, ry1 });
		v.push_back({ rx1, ry2 });
		v.push_back({ rx2, ry1 });
		v.push_back({ rx2, ry2 }); 
		int num=0;
		for (int i = 0; i < 4; i++) {
			num += solution(p1, p2, v[i],v[(i+1)%4]);
		}
		
		if (p1.x <= rx2&&p1.x >= rx1&&p2.x <= rx2&&p2.x >= rx1&&p1.y <= ry2&&p1.y >= ry1&&p2.y <= ry2&&p2.y >= ry1)
			num = 100;
	//	printf("%d\n", num);
		if (num == 0) {
			printf("F\n");
		}
		else if(num>0){
			printf("T\n");
		}
		
		
	}
	return 0;
}
