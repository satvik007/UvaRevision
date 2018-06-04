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
vi a[210];
int visited[210];


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n, n) {
        cin >> m;
        int u, v;

        for(int i = 0; i < n; i++) {
            a[i].clear();
        }

        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }

        memset(visited, 0, sizeof visited);

        bool flag = true;

        function<void(int, int)> dfs = [&](int ind, int col) {
            if(visited[ind]) {
                if(visited[ind] != col) flag = false;
                return;
            }
            visited[ind] = col;
            for(auto el: a[ind]) {
                dfs(el, !col);
            }
        };

        dfs(0, 0);

        if(flag) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";

    }

}