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

int n;
vi a[310];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n, n) {
        int u, v;

        for(int i = 1; i <= n; i++) a[i].clear();

        while(cin >> u >> v, u) {
            a[u].push_back(v);
            a[v].push_back(u);
        }

        bool flag = true;

        vi visited(n + 1, -1);

        function <void(int, int)> dfs = [&](int id, int col) {
            if(visited[id] != -1) {
                if(visited[id] != col) flag = false;
                return;
            }
            visited[id] = col;
            for(auto el: a[id]) dfs(el, !col);
        };


        for(int i = 1; i <= n; i++) {
            if(visited[i] == -1) {
                dfs(i, 0);
            }
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";


    }

}