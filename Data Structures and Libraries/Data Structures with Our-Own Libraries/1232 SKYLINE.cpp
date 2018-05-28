#define BZ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int INF = 1 << 30;

int n;

class SegmentTree {
public:
    int tree[400010];
    SegmentTree() {
        memset(tree, 0, sizeof tree);
    }

    int solve(int p, int l, int r, int i, int j, int h) {
        if(l != r && tree[p] != -1) {
            tree[left(p)] = tree[p];
            tree[right(p)] = tree[p];
        }
        if(l > j || r < i) return 0;
        if(l >= i && r <= j) {
            if(tree[p] == -1) {
                int f = solve(left(p), l, (l + r) / 2, i, j, h);
                int s = solve(right(p), (l + r) / 2 + 1, r, i, j, h);
                if(tree[left(p)] == tree[right(p)]) {
                    tree[p] = tree[left(p)];
                }
                return f + s;
            } else {
                int v = tree[p];
                if(h >= v) {
                    tree[p] = h;
                    return (r - l + 1);
                }
                return 0;
            }
        }
        int v1 = solve(left(p), l, (l + r) / 2, i, j, h);
        int v2 = solve(right(p), (l + r) / 2 + 1, r, i, j, h);
        if(tree[left(p)] == tree[right(p)]) {
            tree[p] = tree[left(p)];
        } else {
            tree[p] = -1;
        }
        return v1 + v2;
    }

    int left(int p) {
        return (p << 1);
    }
    int right(int p) {
        return (p << 1 | 1);
    }
};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n;

        int cnt = 0;
        SegmentTree cur;

        for(int i = 0; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            cnt += cur.solve(1, 0, 100000, u, v - 1, w);
            //cout << cnt << "\n";
        }

        cout << cnt << "\n";

    }


}