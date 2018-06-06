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
int r, c;
int dist[2010][2010];
set <ii> set1;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n, n) {
        memset(dist, -1, sizeof dist);
        set1.clear();
        queue <ii> q;
        r = 0, c = 0;

        for(int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            q.push({u, v});
            dist[u][v] = 0;
            r = max(r, u);
            c = max(c, v);
        }

        cin >> m;

        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            set1.insert({u, v});
            r = max(r, u);
            c = max(c, v);
        }

        int ans = -1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()) {
            ii cur = q.front(); q.pop();
            if(set1.count(cur)) {
                ans = dist[cur.first][cur.second];
                break;
            }
            ii temp;
            for(int i = 0; i < 4; i++) {
                int tx = cur.first + dr[i];
                int ty = cur.second + dc[i];
                if(tx >= 0 && ty >= 0 && tx <= r && ty <= c && dist[tx][ty] == -1) {
                    temp.first = tx;
                    temp.second = ty;
                    dist[tx][ty] = dist[cur.first][cur.second] + 1;
                    q.push(temp);
                }
            }
        }

        cout << ans << "\n";
    }


}