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

int r, c, m, n, k;
int visited[110][110];
int cnt[110][110];


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    int cas = 1;
    while(tc--) {
        cin >> r >> c >> m >> n >> k;

        int kdr[] = {-m, -n, n, m, m, n, -n, -m};
        int kdc[] = {n, m, m, n, -n, -m, -m, -n};

        int dr[] = {-m, n, m, -n};
        int dc[] = {n, m, -n, -m};

        int u, v;
        memset(visited, 0, sizeof visited);
        memset(cnt, 0, sizeof cnt);

        for(int i = 0; i < k; i++) {
            cin >> u >> v;
            visited[u][v] = 2;
        }

        int counter[2] = {};

        auto bfs1 = [&]() {
            queue <ii> q;
            q.push({0, 0});

            ii cur; visited[0][0] = 1;

            while(!q.empty()) {
                cur = q.front(); q.pop();
                for(int i = 0; i < 8; i++) {
                    int tx = cur.first + kdr[i];
                    int ty = cur.second + kdc[i];
                    if(tx >= 0 && ty >= 0 && tx < r && ty < c && visited[tx][ty] != 2) {
                        cnt[cur.first][cur.second]++;
                        if(!visited[tx][ty]) {
                            visited[tx][ty] = 1;
                            q.push({tx, ty});
                        }
                    }
                }
            }
        };

        auto bfs2 = [&]() {
            queue <ii> q;
            q.push({0, 0});

            ii cur; visited[0][0] = 1;

            while(!q.empty()) {
                cur = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int tx = cur.first + dr[i];
                    int ty = cur.second + dc[i];
                    if(tx >= 0 && ty >= 0 && tx < r && ty < c && visited[tx][ty] != 2) {
                        cnt[cur.first][cur.second]++;
                        if(!visited[tx][ty]) {
                            visited[tx][ty] = 1;
                            q.push({tx, ty});
                        }
                    }
                }
            }
        };

        if(n == m || n == 0 || m == 0) {
            bfs2();
        } else {
            bfs1();
        }

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(visited[i][j] == 1) counter[cnt[i][j] % 2]++;
            }
        }



        cout << "Case " << cas++ << ": " << counter[0] << " " << counter[1] << "\n";
    }

}