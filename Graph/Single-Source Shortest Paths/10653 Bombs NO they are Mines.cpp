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

int n, m, k;
int a[1010][1010];
int dist[1010][1010];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n >> m, n || m) {
        //memset(a, 0, sizeof a);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dist[i][j] = -1;
                a[i][j] = 0;
            }
        }
        int k;
        cin >> k;
        for(int i = 0; i < k; i++) {
            int u, v, w;
            cin >> u >> v;
            while(v--) {
                cin >> w;
                a[u][w] = 1;
            }
        }
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;

        function <int()> dfs = [&]() {
            queue <ii> q;
            q.push({sx, sy});

            dist[sx][sy] = 0;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            while(!q.empty()) {
                ii cur = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int tx = cur.first + dr[i];
                    int ty = cur.second + dc[i];
                    if(tx >= 0 && ty >= 0 && tx < n && ty < m && a[tx][ty] == 0 && dist[tx][ty] == -1) {
                        dist[tx][ty] = dist[cur.first][cur.second] + 1;
                        if(tx == dx && ty == dy) {
                            return dist[tx][ty];
                        }
                        q.push({tx, ty});
                    }
                }
            }
        };

        int ans = dfs();
        cout << ans << "\n";

    }

}