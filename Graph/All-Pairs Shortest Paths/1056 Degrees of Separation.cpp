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

const int INF = (int)1e9;

#define maxn 100010

int a[60][60];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, m;

    map <string, int> map1;
    int cas = 1;
    while(cin >> n >> m, n || m) {
        int k = 0;
        map1.clear();
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                a[i][j] = INF;
            }
            a[i][i] = 0;
        }

        for(int i = 0; i < m; i++) {
            string u, v;
            cin >> u >> v;
            if(!map1.count(u)) map1[u] = k++;
            if(!map1.count(v)) map1[v] = k++;
            a[map1[u]][map1[v]] = 1;
            a[map1[v]][map1[u]] = 1;
        }

        for(int q = 0; q < n; q++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    a[i][j] = min(a[i][j], a[i][q] + a[q][j]);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, a[i][j]);
            }
        }
        cout << "Network " << cas++ << ": ";
        if(ans == INF) {
            cout << "DISCONNECTED\n";
        } else {
            cout << ans << "\n";
        }
        cout << "\n";
    }

}