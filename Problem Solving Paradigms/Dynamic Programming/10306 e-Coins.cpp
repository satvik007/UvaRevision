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
int a[110];
int b[110];
int dp[310][310];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }

        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= m; j++) {
                dp[i][j] = INF;
            }
        }

        dp[0][0] = 0;

        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= m; j++) {
                for(int k = 1; k <= n; k++) {
                    if(i >= a[k] && j >= b[k])
                    dp[i][j] = min(dp[i][j], dp[i - a[k]][j - b[k]] + 1);
                }
            }
        }

        int ans = INF;
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= m; j++) {
                if(i * i + j * j == m * m) {
                    ans = min(ans, dp[i][j]);
                }
            }
        }

        if(ans == INF) {
            cout << "not possible\n";
        } else {
            cout << ans << "\n";
        }

    }

}