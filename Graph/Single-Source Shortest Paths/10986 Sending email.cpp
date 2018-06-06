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

int n, m, s, t;
vector <vector <ii>> a;
int dist[20010];

void dijkstra() {
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    pq.push({0, s});
    memset(dist, -1, sizeof dist);
    dist[s] = 0;

    while(!pq.empty()) {
        ii cur = pq.top(); pq.pop();
        if(cur.first > dist[cur.second]) continue;
        if(cur.second == t) {
            return;
        }
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
    int cas = 1;

    while(tc--) {
        cin >> n >> m >> s >> t;
        a.clear();
        a.resize(n);
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            a[u].push_back({v, w});
            a[v].push_back({u, w});
        }

        dijkstra();

        cout << "Case #" << cas++ << ": ";
        if(dist[t] == -1) cout << "unreachable\n";
        else cout << dist[t] << "\n";

    }


}