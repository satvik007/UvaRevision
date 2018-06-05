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

    map <string, int> map1;
    vector <vi> a(30, vi(30));
    vector <string> names;

    vi dfs_num;
    vi dfs_low;
    vi visited;
    vi s;

    int n, m;
    int cas = 1;

    while(cin >> n >> m, n || m) {
        if(cas != 1) cout << "\n";

        names.clear();
        map1.clear();
        int k  = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) a[i][j] = 0;
        }

        for(int i = 0; i < m; i++) {
            string u, v;
            cin >> u >> v;
            if(!map1.count(u)) map1[u] = k++, names.push_back(u);
            if(!map1.count(v)) map1[v] = k++, names.push_back(v);
            a[map1[u]][map1[v]] = 1;
        }

        cout << "Calling circles for data set " << cas++ << ":\n";

        dfs_num.assign(n, -1);
        dfs_low = dfs_num;
        visited.assign(n, 0);
        s.clear();

        int cnt = 0, num = 0;

        function <void(int)> tarjan = [&] (int u) {
            dfs_num[u] = dfs_low[u] = cnt++;
            visited[u] = 1;
            s.push_back(u);

            for(int v = 0; v < n; v++) {
                if(a[u][v]) {
                    if(dfs_num[v] == -1)
                        tarjan(v);
                    if(visited[v])
                        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
                }
            }

            if(dfs_low[u] == dfs_num[u]) {
                while(true) {
                    int v = s.back(); s.pop_back(); visited[v] = 0;
                    cout << names[v];
                    if(u == v) break;
                    cout << ", ";
                }
                cout << "\n";
            }

        };

        for(int i = 0; i < n; i++) {
            if(dfs_num[i] == -1) {
                tarjan(i);
            }
        }
    }
}