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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int n;
    vector <vi> a;

    vi dfs_num(100);
    vi dfs_lo(100);
    vi visited(100);
    vi parent(100);
    bitset <100> art;

    while(cin >> n, n) {
        int u, v;
        a.clear();
        a.resize(n + 1);
        while(cin >> u, u) {
            while(cin.peek() != '\n') {
                cin >> v;
                a[u].push_back(v);
                a[v].push_back(u);
            }
        }

        int root = 0;
        int cnt = 0;

        dfs_num.assign(n + 1, -1);
        dfs_lo.assign(n + 1, -1);
        parent.assign(n + 1, -1);
        art.reset();

        function <void(int)> dfs = [&] (int u) {
            dfs_num[u] = dfs_lo[u] = cnt++;

            for(auto v: a[u]) {
                if(dfs_num[v] == -1) {
                    parent[v] = u;
                    if(u == 1) root++;
                    dfs(v);
                    if(dfs_lo[v] >= dfs_num[u]) art[u] = true;
                    dfs_lo[u] = min(dfs_lo[u], dfs_lo[v]);
                } else if(v != parent[u]) {
                    dfs_lo[u] = min(dfs_lo[u], dfs_num[v]);
                }
            }
        };

        dfs(1);
        art[1] = root > 1;

        int ans = art.count();

        cout << ans << "\n";

    }

}