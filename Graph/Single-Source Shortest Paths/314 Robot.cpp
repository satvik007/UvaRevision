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
int a[60][60];
int dist[60][60][5];

struct Data {
    int x, y, dir;
};


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n >> m, n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;

        string direction;
        cin >> direction;

        int dir;
        if(direction == "north") dir = 0;
        else if(direction == "east") dir = 1;
        else if(direction == "south") dir = 2;
        else if(direction == "west") dir = 3;

        function <int()> bfs = [&] () {

            if(sx == dx && sy == dy) return 0;

            Data cur = {sx, sy, dir};
            queue <Data> q; q.push(cur);
            memset(dist, -1, sizeof dist);
            dist[sx][sy][dir] = 0;
            Data temp;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            while(!q.empty()) {
                cur = q.front(); q.pop();
                temp = cur;
                for(int i = 1; i <= 3; i++) {
                    temp.dir = (cur.dir + i) % 4;
                    if(dist[temp.x][temp.y][temp.dir] == -1) {
                        dist[temp.x][temp.y][temp.dir] = dist[cur.x][cur.y][cur.dir] + 2 - abs(i - 2);
                        q.push(temp);
                    }
                }
                temp = cur;
                for(int i = 1; i <= 3; i++) {
                    int tx = cur.x + dr[cur.dir] * i;
                    int ty = cur.y + dc[cur.dir] * i;
                    int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
                    f1 = a[tx - 1][ty - 1];
                    f2 = a[tx - 1][ty];
                    f3 = a[tx][ty - 1];
                    f4 = a[tx][ty];

                    if(tx > 0 && ty > 0 && tx < n && ty < m && !(f1 || f2 || f3 || f4)) {
                        if(dist[tx][ty][cur.dir] == -1) {
                            dist[tx][ty][cur.dir] = dist[cur.x][cur.y][cur.dir] + 1;
                            temp.x = tx, temp.y = ty;
                            q.push(temp);
                            if(tx == dx && ty == dy) {
                                return dist[tx][ty][cur.dir];
                            }
                        }
                    } else
                        break;
                }
            }

            return -1;
        };

        int ans = bfs();

        cout << ans << "\n";

    }

}