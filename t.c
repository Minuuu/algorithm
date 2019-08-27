#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int a[30][30]; //입력 
bool c[30][30]; //방문 여부
vector<pair<int, int>> b[30][30]; //(i,j)에서 방석 1개만 이용해서 갈수 있는 모든 곳
int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { -1,-2,-2,-1,1,2,2,1 };
long long cnt[30][30]; //방법의 수
long long dist[30][30]; //방석의 개수(거리 가중치)
int n, m;
void bfs(int sx, int sy) {
	memset(c, false, sizeof(c));
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	c[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (a[x][y] != 1 && !(sx == x && sy == y)) { //1이 아니고(방석이 깔린곳이 아니고) 시작위치가 아니면
			b[sx][sy].push_back(make_pair(x, y)); //방석 1개만 이용해서 갈수 있는 곳 추가
		}
		else {
			for (int k = 0; k<8; k++) { //그게 아니면 bfs 돌리기
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (c[nx][ny]) continue;
				if (a[nx][ny] == 2) continue;
				q.push(make_pair(nx, ny));
				c[nx][ny] = true;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			cin >> a[i][j];
		}
	}
	int sx, sy, ex, ey;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (a[i][j] != 2) { //돌멩이가 아니라면 해당위치에서 bfs 호출
				bfs(i, j); //각 칸에 대해서 현재 위치에서 방석 1개를 놓고 갈수 있는 곳을 b백터에 저장한다
			}
			if (a[i][j] == 3) {
				sx = i;
				sy = j;
			}
			else if (a[i][j] == 4) {
				ex = i;
				ey = j;
			}
		}
	}
	memset(c, false, sizeof(c));
	memset(dist, -1, sizeof(dist));
	cnt[sx][sy] = 1; //시작 위치 가는 방법의수 1
	dist[sx][sy] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	printf("%d %d\n", sx,sy);
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cout<<b[x][y].size()<<endl;
		for (auto &p : b[x][y]) { //auto 참조 요소를 사용하면 백터를 참조할 수 있다 백터의 모든요소를 방문한다
			int nx = p.first; // x,y에서 방석 1개만 놓고 갈 수 있는데
			int ny = p.second;
			if (dist[nx][ny] == -1) { //아직 방문하지 않은 곳이면 next까지의 최단 경로 개수는 now까지와 같다
				dist[nx][ny] = dist[x][y] + 1;
				cnt[nx][ny] = cnt[x][y];
				q.push(make_pair(nx, ny));
			}
			else if (dist[nx][ny] == dist[x][y] + 1) { //방문한 곳인데 next 까지의 거리가 now +1이면 또다른 최단 경로이다
				cnt[nx][ny] += cnt[x][y];
			}
		}
	}
	if (dist[ex][ey] == -1) {
		cout << -1 << '\n';
	}
	else {
		cout << dist[ex][ey] - 1 << '\n';
		if (dist[ex][ey] != -1) {
			cout << cnt[ex][ey] << '\n';
		}
	}
	return 0;
}


