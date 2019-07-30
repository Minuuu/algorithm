#include <iostream>
#include <map>
#include <set>
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define mp(a,b) make_pair(a,b)
using namespace std;
int main() {
    int x, y, t = 1;
    while (1) {
        map<int, int> m;
        set<int> s;
        bool flag = true;
        while (1) {
            cin >> x >> y;
            if (x < 0 && y < 0) return 0;
            if (x == 0 && y == 0) break;
            if (m.count(y) == 0) {
                if (m.count(x) == 1 && m.at(x) == y) flag = false;
                else {
                    m.insert(mp(y, x));
                    s.insert(x);
                }
            }
            else flag = false;
        }
        int cnt = 0;
        for (int root : s) if (m.count(root) == 0) cnt++;
        if (flag && cnt == 1 || s.empty()) cout << "Case " << t << " is a tree.\n";
        else cout << "Case " << t << " is not a tree.\n";
        t++;
    }
}

