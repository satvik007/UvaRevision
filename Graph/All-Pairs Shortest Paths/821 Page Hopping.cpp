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

const int INF = 1 << 28;

#define maxn 100010

int a[101][101];


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(3);

    int u, v;
    int n;
    int cas = 1;

    while(cin >> u >> v, u || v) {
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                a[i][j] = INF;
            }
            a[i][i] = 0;
        }

        a[u - 1][v - 1] = 1;
        n = max(u, v);
        while(cin >> u >> v, u || v) {
            a[u - 1][v - 1] = 1;
            n = max(n, max(u, v));
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }

        ll cnt = 0;
        int val = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] != INF && i != j) cnt += a[i][j], val++;
            }
        }

        cout << "Case " << cas++ << ": average length between pages = " << (1.0 * cnt / val) << " clicks\n";
    }

}