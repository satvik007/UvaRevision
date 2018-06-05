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

    vi dfs_num(10000);
    vi dfs_lo(10000);
    vi art(10000);
    vi parent(10000);

    vector <vi> a;
    vector <ii> ans;

    while(cin >> n >> m, n || m) {
        int x, y;
        a.clear();
        a.resize(n);

        while(cin >> x >> y, x != -1) {
            a[x].push_back(y);
            a[y].push_back(x);
        }

        ans.clear();
        dfs_num.assign(n, -1);
        dfs_lo.assign(n, 0);
        art.assign(n, 0);
        parent.assign(n, -1);

        int root, sons, cnt = 0;

        function <void(int)> dfs = [&](int u) {
            dfs_num[u] = dfs_lo[u] = cnt++;
            for(auto v: a[u]) {
                if(dfs_num[v] == -1) {
                    if(u == root) sons++;
                    parent[v] = u;
                    dfs(v);
                    if(dfs_lo[v] >= dfs_num[u]) {
                        art[u]++;
                    }
                    dfs_lo[u] = min(dfs_lo[u], dfs_lo[v]);
                } else if(v != parent[u]) {
                    dfs_lo[u] = min(dfs_lo[u], dfs_num[v]);
                }
            }
        };


        for(int i = 0; i < n; i++) {
            if(dfs_num[i] == -1) {
                root = i, sons = 0;
                dfs(i);
                art[i] = sons - 1;
            }
        }

        for(int i = 0; i < n; i++) {
            ans.push_back({i, art[i]});
        }

        auto comp = [&](ii x, ii y) {
            if(x.second == y.second) return x.first < y.first;
            return x.second > y.second;
        };

        sort(ans.begin(), ans.end(), comp);

        for(int i = 0; i < m; i++) {
            cout << ans[i].first << " " << ans[i].second + 1 << "\n";
        }

        cout << "\n";

    }

}