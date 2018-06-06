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

int n, m, q;
vector <pair <int, ii> > a;
vector <vector<ii>> adj;

class UnionFind {
public:
    vi p, rank;
    UnionFind() {
        p.resize(n);
        rank.assign(n, 1);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int findSet(int i) {
        while(i != p[i]) p[i] = p[p[i]], i = p[i];
        return i;
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        i = findSet(i);
        j = findSet(j);
        if(i != j) {
            if(rank[i] < rank[j]) p[i] = j;
            else {
                p[j] = i;
                if(rank[i] == rank[j]) rank[i]++;
            }
        }
    }
};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int cas = 1;

    while(cin >> n >> m >> q, n) {
        if(cas != 1) cout << "\n";

        adj.clear();
        adj.resize(n);
        a.clear();
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            a.push_back({w, {u, v}});
        }
        sort(a.begin(), a.end());

        UnionFind cur;

        for(auto el: a) {
            if(!cur.isSameSet(el.second.first, el.second.second)) {
                cur.unionSet(el.second.first, el.second.second);
                adj[el.second.first].push_back({el.second.second, el.first});
                adj[el.second.second].push_back({el.second.first, el.first});
            }
        }

        int ans;

        function <void(int, int, int, int)> dfs = [&](int u, int last, int v, int val) {
            if(u == v) {
                ans = val;
                return;
            }
            for(auto el: adj[u]) {
                if(el.first != last) {
                    dfs(el.first, u, v, max(val, el.second));
                }
            }
        };

        cout << "Case #" << cas++ << "\n";

        while(q--) {
            int u, v;
            cin >> u >> v;
            ans = -10;
            dfs(u - 1, -1, v - 1, 0);
            if(ans == -10) cout << "no path\n";
            else cout << ans << "\n";
        }

    }

}