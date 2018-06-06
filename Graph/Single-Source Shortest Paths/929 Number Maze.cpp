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

int a[1010][1010];
int dist[1010][1010];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        int n, m;
        cin >> n >> m;

        memset(dist, -1, sizeof dist);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        priority_queue <pair<int, ii>, vector <pair<int, ii> >, greater <pair<int, ii> > > pq;
        pq.push({a[0][0], {0, 0}});
        dist[0][0] = a[0][0];
        int ans = -1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()) {
            pair <int, ii> cur = pq.top(); pq.pop();
            if(dist[cur.second.first][cur.second.second] < cur.first) continue;
            if(cur.second.first == n - 1 && cur.second.second == m - 1) {
                break;
            }
            for(int i = 0; i < 4; i++) {
                int tx = cur.second.first + dr[i];
                int ty = cur.second.second + dc[i];
                if(tx >= 0 && ty >= 0 && tx < n && ty < m) {
                    if(dist[tx][ty] == -1 || dist[tx][ty] > cur.first + a[tx][ty]) {
                        dist[tx][ty] = cur.first + a[tx][ty];
                        pq.push({dist[tx][ty], {tx, ty}});
                    }
                }
            }

        }

        cout << dist[n - 1][m - 1] << "\n";

    }

}929 Number Maze
