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

#define maxn 100010

int n, m;
int a[510][510];
ii b[510];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n >> m, n || m) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int q;
        cin >> q;
        int u, v;

        while(q--) {
            cin >> u >> v;
            for(int i = 0; i < n; i++) {
                b[i].first = lower_bound(a[i], a[i] + m, u) - a[i];
                b[i].second = upper_bound(a[i], a[i] + m, v) - a[i];
            }
            int ans = 0;
            for(int i = 0; i < n; i++) {
                for(int j = i; j < n; j++) {
                    if(b[i].first == b[i].second) break;
                    ans = max(ans, min(j - i + 1, b[j].second - b[i].first));
                }
            }
            cout << ans << "\n";
        }
        cout << "-\n";
    }


}