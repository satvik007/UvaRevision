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
vector <vi> a;
int visited[110];
vi ord;

void dfs(int u) {
    visited[u] = 1;
    for(auto el: a[u]) {
        if(!visited[el]) {
            dfs(el);
        }
    }
    ord.push_back(u);
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n >> m, n || m) {
        int u, v;
        a.clear();
        a.resize(n + 1);
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            a[u].push_back(v);
        }

        memset(visited, 0, sizeof visited);

        ord.clear();

        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                dfs(i);
            }
        }

        reverse(ord.begin(), ord.end());

        for(int i = 0; i < ord.size(); i++) {
            if(i) cout << " ";
            cout << ord[i];
        }
        cout << "\n";

    }


}