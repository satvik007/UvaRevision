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

    int tc;
    cin >> tc;
    vector <vi> a;

    vi dfs_num;
    vi dfs_low;
    vi visited;
    vi scc;
    vi s;

    while(tc--) {
        cin >> n >> m;
        a.clear();
        a.resize(n + 1);

        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
        }

        s.clear();
        dfs_num.assign(n + 1, -1);
        dfs_low = dfs_num;
        visited.assign(n + 1, 0);
        scc.assign(n + 1, -1);
        int cnt = 0, num = 0;

        function <void(int)> tarjan = [&](int u) {
            dfs_num[u] = dfs_low[u] = cnt++;
            visited[u] = 1;
            s.push_back(u);

            for(auto v: a[u]) {
                if(dfs_num[v] == -1)
                    tarjan(v);
                if(visited[v])
                    dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            }

            if(dfs_low[u] == dfs_num[u]) {
                while(true) {
                    int v = s.back(); s.pop_back(); visited[v] = 0;
                    scc[v] = num;
                    if(u == v) break;
                }
                num++;
            }
        };

        for(int i = 1; i <= n; i++) {
            if(dfs_num[i] == -1)
                tarjan(i);
        }

        vi ind(num, 0);

        for(int i = 1; i <= n; i++) {
            for(auto v: a[i]) {
                if(scc[v] != scc[i])
                    ind[scc[v]]++;
            }
        }

        int ans = 0;

        for(int i = 0; i < num; i++) {
            if(ind[i] == 0) ans++;
        }

        cout << ans << "\n";



    }

}