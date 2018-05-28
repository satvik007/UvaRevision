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

int a[510][510];
int n;
int tree1[2010][2010];
int tree2[2010][2010];

class SegmentTree {
public:
    static const int inf = (int) 1e9;
    SegmentTree() {
        build1(1, 1, 0, n - 1, 0, n - 1);
        build2(1, 1, 0, n - 1, 0, n - 1);
    }

    int build1(int p, int q, int u, int d, int l, int r) {
        if(u > d || l > r) return inf;
        if(u == d && l == r) {
            return tree1[p][q] = a[u][l];
        }
        int b[4];
        b[0] = build1(left(p), left(q), u, (u + d) / 2, l, (l + r) / 2);
        b[1] = build1(left(p), right(q), u, (u + d) / 2, (l + r) / 2 + 1, r);
        b[2] = build1(right(p), left(q), (u + d) / 2 + 1, d, l, (l + r) / 2);
        b[3] = build1(right(p), right(q), (u + d) / 2 + 1, d, (l + r) / 2 + 1, r);
        return tree1[p][q] = *min_element(b, b+4);
    }
    int build2(int p, int q, int u, int d, int l, int r) {
        if(u > d || l > r) return -inf;
        if(u == d && l == r) {
            return tree2[p][q] = a[u][l];
        }
        int b[4];
        b[0] = build2(left(p), left(q), u, (u + d) / 2, l, (l + r) / 2);
        b[1] = build2(left(p), right(q), u, (u + d) / 2, (l + r) / 2 + 1, r);
        b[2] = build2(right(p), left(q), (u + d) / 2 + 1, d, l, (l + r) / 2);
        b[3] = build2(right(p), right(q), (u + d) / 2 + 1, d, (l + r) / 2 + 1, r);
        return tree2[p][q] = *max_element(b, b+4);
    }

    int modify1(int p, int q, int u, int d, int l, int r, int x, int y, int v) {
        if(u > d || l > r) return inf;
        if(u > x || d < x || l > y || r < y) return tree1[p][q];
        if(u == d && u == x && l == r && l == y) {
            return tree1[p][q] = v;
        }
        int b[4];
        b[0] = modify1(left(p), left(q), u, (u + d) / 2, l, (l + r) / 2, x, y, v);
        b[1] = modify1(left(p), right(q), u, (u + d) / 2, (l + r) / 2 + 1, r, x, y, v);
        b[2] = modify1(right(p), left(q), (u + d) / 2 + 1, d, l, (l + r) / 2, x, y, v);
        b[3] = modify1(right(p), right(q), (u + d) / 2 + 1, d, (l + r) / 2 + 1, r, x, y, v);
        return tree1[p][q] = *min_element(b, b+4);
    }
    int modify2(int p, int q, int u, int d, int l, int r, int x, int y, int v) {
        if(u > d || l > r) return -inf;
        if(u > x || d < x || l > y || r < y) return tree2[p][q];
        if(u == d && u == x && l == r && l == y) {
            return tree2[p][q] = v;
        }
        int b[4];
        b[0] = modify2(left(p), left(q), u, (u + d) / 2, l, (l + r) / 2, x, y, v);
        b[1] = modify2(left(p), right(q), u, (u + d) / 2, (l + r) / 2 + 1, r, x, y, v);
        b[2] = modify2(right(p), left(q), (u + d) / 2 + 1, d, l, (l + r) / 2, x, y, v);
        b[3] = modify2(right(p), right(q), (u + d) / 2 + 1, d, (l + r) / 2 + 1, r, x, y, v);
        return tree2[p][q] = *max_element(b, b + 4);
    }

    int query1(int p, int q, int u, int d, int l, int r, int x1, int y1, int x2, int y2) {
        if(u > d || l > r) return inf;
        if(u > y1 || d < x1 || l > y2 || r < x2) return inf;
        if(u >= x1 && d <= y1 && l >= x2 && r <= y2) {
            return tree1[p][q];
        }
        int b[4];
        b[0] = query1(left(p), left(q), u, (u + d) / 2, l, (l + r) / 2, x1, y1, x2, y2);
        b[1] = query1(left(p), right(q), u, (u + d) / 2, (l + r) / 2 + 1, r, x1, y1, x2, y2);
        b[2] = query1(right(p), left(q), (u + d) / 2 + 1, d, l, (l + r) / 2, x1, y1, x2, y2);
        b[3] = query1(right(p), right(q), (u + d) / 2 + 1, d, (l + r) / 2 + 1, r, x1, y1, x2, y2);
        return *min_element(b, b+4);
    }
    int query2(int p, int q, int u, int d, int l, int r, int x1, int y1, int x2, int y2) {
        if(u > d || l > r) return -inf;
        if(u > y1 || d < x1 || l > y2 || r < x2) return -inf;
        if(u >= x1 && d <= y1 && l >= x2 && r <= y2) return tree2[p][q];
        int b[4];
        b[0] = query2(left(p), left(q), u, (u + d) / 2, l, (l + r) / 2, x1, y1, x2, y2);
        b[1] = query2(left(p), right(q), u, (u + d) / 2, (l + r) / 2 + 1, r, x1, y1, x2, y2);
        b[2] = query2(right(p), left(q), (u + d) / 2 + 1, d, l, (l + r) / 2, x1, y1, x2, y2);
        b[3] = query2(right(p), right(q), (u + d) / 2 + 1, d, (l + r) / 2 + 1, r, x1, y1, x2, y2);
        return *max_element(b, b + 4);
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

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    SegmentTree cur;

    int q;
    cin >> q;

    char type;
    int x1, y1, x2, y2;
    int x, y, z;
    while(q--) {
        cin >> type;
        if(type == 'q') {
            cin >> x1 >> y1 >> x2 >> y2; x1--; y1--; x2--; y2--;
            cout << cur.query2(1, 1, 0, n - 1, 0, n - 1, x1, x2, y1, y2);
            cout << " " << cur.query1(1, 1, 0, n - 1, 0, n - 1, x1, x2, y1, y2) << "\n";
        } else {
            cin >> x >> y >> z; x--; y--;
            cur.modify1(1, 1, 0, n - 1, 0, n - 1, x, y, z);
            cur.modify2(1, 1, 0, n - 1, 0, n - 1, x, y, z);
        }
    }

}