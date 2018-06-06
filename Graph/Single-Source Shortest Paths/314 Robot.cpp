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

        function <bool(int x, int y)> valid = [&](int x, int y) {
            int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
            f1 = a[x - 1][y - 1];
            f2 = a[x - 1][y];
            f3 = a[x][y - 1];
            f4 = a[x][y];
            if(x <= 0 || y <= 0 || x >= n || y >= m) return false;
            return !(f1 || f2 || f3 || f4);
        };

        function <int()> bfs = [&] () {

            Data cur = {sx, sy, dir};
            queue <Data> q;

            if(valid(sx, sy)) q.push(cur);

            memset(dist, -1, sizeof dist);
            dist[sx][sy][dir] = 0;
            Data temp;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            while(!q.empty()) {
                cur = q.front(); q.pop();
                if(cur.x == dx && cur.y == dy) return dist[cur.x][cur.y][cur.dir];
                temp = cur;

                temp.dir = (cur.dir + 1) % 4;
                if(dist[temp.x][temp.y][temp.dir] == -1) {
                    dist[temp.x][temp.y][temp.dir] = dist[cur.x][cur.y][cur.dir] + 1;
                    q.push(temp);
                }

                temp.dir = (cur.dir + 3) % 4;
                if(dist[temp.x][temp.y][temp.dir] == -1) {
                    dist[temp.x][temp.y][temp.dir] = dist[cur.x][cur.y][cur.dir] + 1;
                    q.push(temp);
                }

                temp = cur;
                for(int i = 1; i <= 3; i++) {
                    int tx = cur.x + dr[cur.dir] * i;
                    int ty = cur.y + dc[cur.dir] * i;

                    if(valid(tx, ty)) {
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