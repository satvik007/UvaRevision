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

vector <string> a;
string s;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int n, m, k;
    while(cin >> n >> m >> k, n) {
        a.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> s;
        int x = 0, y = 0;
        int dir = 0;
        bool flag = true;
        for(int i = 0; i < n && flag; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] >= 'A') {
                    x = i, y = j;
                    if(a[i][j] == 'N') dir = 0;
                    else if(a[i][j] == 'S') dir = 2;
                    else if(a[i][j] == 'L') dir = 1;
                    else if(a[i][j] == 'O') dir = 3;
                    flag = false;
                    break;
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'D') {
                dir = (dir + 1) % 4;
            } else if(s[i] == 'E') {
                dir = (dir + 3) % 4;
            } else if(s[i] == 'F') {

                int tx = x + dr[dir];
                int ty = y + dc[dir];
                if(tx >= 0 && ty >= 0 && tx < n && ty < m && a[tx][ty] != '#') {
                    if(a[tx][ty] == '*') {
                        cnt++;
                        a[tx][ty] = '.';
                    }
                    x = tx, y = ty;
                }
            }
        }

        cout << cnt << "\n";

    }

}