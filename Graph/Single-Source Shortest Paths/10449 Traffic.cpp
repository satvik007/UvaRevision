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
#define p(x) ((x) * (x) * (x))

int n, m;
int b[210];
int dist[210];
int used[210];

vector <vi> a;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int cas = 1;

    while(cin >> n) {
        for(int i = 0; i < n; i++) cin >> b[i];
        cin >> m;
        a.clear();
        a.resize(n);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            a[u].push_back(v);
        }

        int q;
        cin >> q;

        cout << "Set #" << cas++ << "\n";

        fill(dist, dist + n, INF);
        dist[0] = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n; j++) {
                for(auto v: a[j]) {
                    dist[v] = min(dist[v], dist[j] + p(b[v] - b[j]));
                }
            }
        }


        memset(used, 0, sizeof used);
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n; j++) {
                for(auto v: a[j]) {
                    if(dist[v] > dist[j] + p(b[v] - b[j])) {
                        dist[v] = dist[j] + p(b[v] - b[j]);
                        used[v] = 1;
                    }
                }
            }
        }

        while(q--) {
            int u;
            cin >> u; u--;
            //cout << dist[u] << "\n";
            if(dist[u] < 3 || used[u] || dist[u] > INF / 2) cout << "?\n";
            else cout << dist[u] << "\n";

        }
    }


}