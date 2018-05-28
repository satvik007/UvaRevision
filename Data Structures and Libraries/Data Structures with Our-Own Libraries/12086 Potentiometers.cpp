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

#define LSOne(a) ((a) & (-(a)))

int a[200010];
ll ft[200010];
int n;

class BIT {
public:
    BIT () {
        memset(ft, 0, sizeof ft);
        for(int i = 1; i <= n; i++) {
            modify(i, a[i]);
        }
    }
    ll query(int u, int v) {
        return rsq(v) - ((u == 1) ? 0 : rsq(u - 1));
    }
    ll rsq(int p) {
        ll res = 0;
        for(; p > 0; p -= LSOne(p)) {
            res += ft[p];
        }
        return res;
    }
    void modify(int p, int v) {
        for(; p <= n; p += LSOne(p))
            ft[p] += v;
    }

};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int cas = 1;
    while(cin >> n, n) {
        if(cas != 1) cout << "\n";
        cout << "Case " << cas++ <<  ":\n";

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        string s;
        char type;
        int u, v;

        BIT cur;


        cin.ignore();
        while(getline(cin, s), s != "END") {
            stringstream sin(s);
            sin >> type >> u >> v;
            if(type == 'S') {
                cur.modify(u, v - a[u]);
                a[u] = v;
            } else {
                cout << cur.query(u, v) << "\n";
            }
        }
    }

}