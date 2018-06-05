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

    int n, m;

    vi dfs_num;
    vi dfs_low;
    vi visited;
    vi s;
    vector <vi> a;

    while(cin >> n >> m, n || m) {
        a.clear();
        a.resize(n);
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            if(w == 1) {
                a[u].push_back(v);
            } else if(w == 2) {
                a[u].push_back(v);
                a[v].push_back(u);
            }
        }

        dfs_num.assign(n, -1);
        dfs_low = dfs_num;
        visited.assign(n, 0);
        s.clear();
        int cnt = 0, num = 0;

        function <void(int)> dfs = [&](int u) {
            dfs_num[u] = dfs_low[u] = cnt++;
            visited[u] = 1;
            s.push_back(u);

            for(auto v: a[u]) {
                if(dfs_num[v] == -1)
                    dfs(v);
                if(visited[v])
                    dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            }

            if(dfs_num[u] == dfs_low[u]) {
                while(true) {
                    int v = s.back(); s.pop_back();
                    visited[v] = 0;
                    if(u == v) break;
                }

                num++;
            }
        };

        for(int i = 0; i < n; i++) {
            if(dfs_num[i] == -1)
                dfs(i);
        }

        if(num > 1) cout << 0 << "\n";
        else cout << "1\n";

    }

}