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

int n, x, t, k;
int p[110];
int c[110];
int dp[110][22][1200];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(2);

    while(cin >> n >> x >> t >> k, n) {
        n++;
        for(int i = 1; i <= k; i++) {
            cin >> p[i];
            int u, res = 0;
            for(int j = 0; j < n; j++) {
                cin >> u; res += u;
            }
            c[i] = res;
        }

        int money = x * n;
        int tea = t * n;

        for(int i = 0; i <= k; i++) {
            for(int j = 0; j <= 2 * n; j++) {
                for(int m = 0; m <= money; m++) {
                    dp[i][j][m] = 0;
                }

            }
        }

        for(int j = 0; j <= 2 * n; j++) {
            for(int i = 1; i <= k; i++) {
                for(int m = 0; m <= money; m++) {
                    dp[i][j][m] = dp[i - 1][j][m];
                    if(m >= p[i] && j >= 1) dp[i][j][m] = max(dp[i][j][m], dp[i - 1][j - 1][m - p[i]] + c[i]);
                    if(m >= 2 * p[i] && j >= 2) dp[i][j][m] = max(dp[i][j][m], dp[i - 1][j - 2][m - 2 * p[i]] + 2 * c[i]);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= 2 * n; i++) {
            for(int j = 0; ceil((j + tea) * 1.1L) <= money; j++) {
                ans = dp[k][i][j];
            }
        }

        cout << 1.0L * ans / n << "\n";
    }

}