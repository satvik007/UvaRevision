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
    vector <ii> ans;

    vi dfs_num;
    vi dfs_lo;
    vi parent;


    while(cin >> n) {
        int x, y, z;
        char null;
        a.clear();
        a.resize(n);

        for(int i = 0; i < n; i++) {
            cin >> x >> null >> y >> null;
            for(int j = 0; j < y; j++) {
                cin >> z;
                a[x].push_back(z);
            }
        }

        ans.clear();
        dfs_num.assign(n, -1);
        dfs_lo.assign(n, 0);
        parent.assign(n, -1);
        int root, cnt, sons;


        function <void(int)> dfs = [&](int u) {
            dfs_num[u] = dfs_lo[u] = cnt++;
            for(auto v: a[u]) {
                if(dfs_num[v] == -1) {
                    if(u == root) sons++;
                    parent[v] = u;
                    dfs(v);
                    if(dfs_lo[v] > dfs_num[u]) {
                        ans.push_back({u, v});
                    }
                    dfs_lo[u] = min(dfs_lo[u], dfs_lo[v]);
                } else if(v != parent[u]) {
                    dfs_lo[u] = min(dfs_lo[u], dfs_num[v]);
                }
            }
        };

        cnt = 0;

        for(int i = 0; i < n; i++) {
            if(dfs_num[i] == -1) {
                sons = 0;
                root = i;
                dfs(i);
            }
        }

        cout << ans.size() << " critical links\n";
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i].first > ans[i].second)
                swap(ans[i].first, ans[i].second);
        }
        sort(ans.begin(), ans.end());

        for(auto u: ans) {
            cout << u.first << " - " << u.second << "\n";
        }

        cout << "\n";


    }

}