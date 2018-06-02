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
int m, n;
int p[105], g[105];
int dp[105][10010];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> m >> n) {
        for(int i = 1; i <= n; i++) {
            cin >> p[i] >> g[i];
        }
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m + 200; j++) {
                dp[i][j] = -INF;
            }
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m + 200; j++) {
                dp[i][j] = dp[i - 1][j];
                if(j >= p[i]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - p[i]] + g[i]);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m + 200; j++) {
                if(j > m && j <= 2000) continue;
                ans = max(ans, dp[i][j]);
            }
        }

        cout << ans << "\n";
    }

}