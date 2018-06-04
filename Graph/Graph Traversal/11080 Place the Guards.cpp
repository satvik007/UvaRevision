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

    int tc;
    cin >> tc;

    vector <vi> a;

    while(tc--) {
        int n, m;
        cin >> n >> m;

        a.clear();
        a.resize(n);

        int u, v;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }

        bool flag;
        vi visited(n, -1);
        flag = true;
        int ans = 0;

        function <void(int, int)> dfs = [&](int id, int col) {
            if(visited[id] != -1) {
                if(visited[id] != col) flag = false;
                return;
            }
            u++;
            visited[id] = col;
            v += col;

            for(auto el: a[id]) {
                dfs(el, !col);
            }

        };


        for(int i = 0; i < n; i++) {
            if(visited[i] == -1) {
                u = 0, v = 0;
                dfs(i, 0);
                ans += max(1, min(v, u - v));
            }
        }

        if(flag) cout << ans << "\n";
        else cout << "-1\n";


    }

}