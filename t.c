//[SWEA] 5656 - 벽돌 깨기
#include<iostream>
#include<algorithm>
#define INF 1000
using namespace std;

int N, W, H;
int map[15][12] = { 0 };
int dr[] = { 0,1,0,-1 };//동남북서
int dc[] = { 1,0,-1,0 };
int minCount = INF;

void copy(int(*a)[12], int(*b)[12]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            b[i][j] = a[i][j];
        }
    }
}//복사
bool check_range(int x, int y){
    if (x >= 0 && y >= 0 && x < H && y < W)
        return true;
    else
        return false;

}//범위검사

void reset() {
    int ans = 0;
    for (int i = 0; i < W; i++) {
        for (int j = H-1; j >=1; j--) {
            for (int k = j - 1; k >= 0; k--) {
                if (map[j][i] != 0) break;
                if (map[k][i] != 0) {
                    map[j][i] = map[k][i];
                    map[k][i] = 0;
                    break;
                }
            }
        }
    }
}//벽돌제거 후 아래로 정렬

void boom(int row, int col) {
    if (!map[row][col]) return;
    int k = map[row][col];
    map[row][col] = 0;
    for (int i = 0; i < k; i++) {
        for (int z = 0; z < 4; z++) {
            int nr = row + dr[z] * i;
            int nc = col + dc[z] * i;
            if (check_range(nr,nc) && map[nr][nc] != 0) {
                boom(nr, nc);
            }
        }
    }
}//벽돌제거

void solve(int n) {
    int copy_map[15][12] = { 0 };
    copy(map, copy_map);
    if (n == N) {
        int cnt = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (map[i][j] != 0) cnt++;
            }
        }
        if (minCount > cnt)minCount = cnt;
        return;
    }
    for (int i = 0; i < W; i++) {
        int x = 0, y = i;
        while (check_range(x, y) && map[x][y] == 0)
            x++;
        boom(x, y);
        reset();
        solve(n + 1);
        copy(copy_map,map);
    }
}//0~(W-1) 사이에 구슬을 N번 투하하는 모든 경우

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        minCount = INF;
        cin >> N >> W >> H;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> map[i][j];
            }
        }
        solve(0);
        cout << "#" << test_case << ' ' << minCount << '\n';
    }
    return 0;
}
