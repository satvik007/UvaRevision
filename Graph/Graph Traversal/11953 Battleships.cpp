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

int n;
vector <string> a;


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;
    int cas = 1;
    while(tc--) {
        cin >> n;
        a.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int cnt = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        function<void(int, int)> ff = [&](int r, int c) {
            if(r < 0 || c < 0 || r >= n || c >= n || a[r][c] == '.') return;
            a[r][c] = '.';
            for(int i = 0; i < 4; i++) {
                ff(r + dr[i], c + dc[i]);
            }
            return;
        };

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 'x') {
                    cnt++;
                    ff(i, j);
                }
            }
        }

        cout << "Case " << cas++ << ": " << cnt << "\n";
    }

}