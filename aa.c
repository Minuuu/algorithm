#include <cstdio>

#include <vector>

using namespace std;

#define MAX 200001

#define mod 1000000007

typedef long long ll;

struct Segment {

    vector<ll> tree;

    int size;

    Segment() {

        tree.resize(4 * MAX, 0);

        size = MAX;

    }

    ll update(int idx, int node, ll val, int nL, int nR) {

        if (idx < nL || idx > nR) return tree[node];

        if (nL == nR) {

            return tree[node] += val;

        }

        int mid = (nL + nR) / 2;

        return tree[node] = update(idx, node * 2, val, nL, mid) + update(idx, node * 2 + 1, val, mid + 1, nR);

    }

    ll update(int idx, ll val) {

        return update(idx, 1, val, 0, size - 1);

    }


    ll query(int node, int l, int r, int nL, int nR) {

        if (r < nL || l > nR) return 0;

        if (l <= nL && nR <= r) return tree[node];


        int mid = (nL + nR) / 2;

        return query(node * 2, l, r, nL, mid) + query(node * 2 + 1, l, r, mid + 1, nR);

    }

    ll query(int l, int r) {

        return query(1, l, r, 0, size - 1);

    }

};

int N;

int input;

int main() {

    Segment seg_sum, seg_cnt;

    scanf("%d", &N);


    scanf("%d", &input);

    seg_sum.update(input, input);        // 구간 거리 합

    seg_cnt.update(input, 1);            // 구간 카운트 합


    long long ans = 1;

    for (int n = 1;n < N;n++) {

        scanf("%d", &input);

        seg_sum.update(input, input);

        seg_cnt.update(input, 1);


        ll sum1 = seg_sum.query(0, input - 1);        //기준보다 작은경우

        ll sum2 = seg_sum.query(input + 1, MAX);    //기준보다 큰 경우

        ll cnt1 = seg_cnt.query(0, input - 1);

        ll cnt2 = seg_cnt.query(input + 1, MAX);


        ll cost = (sum2 - input*cnt2) % mod + (input*cnt1 - sum1) % mod;
		printf("%lld %lld\n", cnt2, sum2);
        ans *= cost%mod;

        ans %= mod;

    }

    printf("%lld\n", ans);

    return 0;

}

