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
vector <string> a;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int ff(int r, int c, char c1, char c2) {
    c = (c + m) % m;
    if(r < 0 || r >= n || a[r][c] != c1) return 0;
    a[r][c] = c2;
    int ans = 1;
    for(int k = 0; k < 4; k++) {
        ans += ff(r + dr[k], c + dc[k], c1, c2);
    }
    return ans;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n >> m) {
        a.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int u, v;
        cin >> u >> v;

        char c1 = a[u][v];
        char c2 = ' ';

        for(int i = 0; i < n && c2 == ' '; i++) {
            for(int j = 0; j < m; j++) {
                if(tolower(a[i][j]) != tolower(c1)) {
                    c2 = a[i][j];
                    break;
                }
            }
        }

        ff(u, v, c1, c2);

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == c1) {
                    int cur = ff(i, j, c1, c2);
                    ans = max(ans, cur);
                }
            }
        }

        cout << ans << "\n";

    }

}