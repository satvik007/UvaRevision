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

int n, e, t, m;
vector <vector<ii>> a;
int dist[110];

void dijkstra() {
    memset(dist, -1, sizeof dist);
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    pq.push({0, e});
    dist[e] = 0;
    while(!pq.empty()) {
        ii cur = pq.top(); pq.pop();
        if(cur.first > dist[cur.second]) continue;
        for(auto v: a[cur.second]) {
            if(dist[v.first] == -1 || dist[v.first] > cur.first + v.second) {
                dist[v.first] = cur.first + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n >> e >> t >> m;
        a.clear(); a.resize(n);
        e--;

        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            a[v].push_back({u, w});
        }

        dijkstra();

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dist[i] <= t && dist[i] != -1) ans++;
        }

        cout << ans << "\n";
        if(tc) cout << "\n";
    }

}