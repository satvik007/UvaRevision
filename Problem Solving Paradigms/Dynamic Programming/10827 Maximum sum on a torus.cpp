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
int a[152][152];
int dp[152][152];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> a[i][j];
                a[i + n][j] = a[i][j];
                a[i][j + n] = a[i][j];
                a[i + n][j + n] = a[i][j];
            }
        }
        int res = -INF;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                memset(dp, 0, sizeof dp);
                for(int p = 0; p < n; p++) {
                    for(int q = 0; q < n; q++) {
                        dp[i + p][j + q] = dp[i + p - 1][j + q] + dp[i + p][j + q - 1] - dp[i + p - 1][j + q - 1] + a[i + p][j + q];
                        res = max(res, dp[i + p][j + q]);
                    }
                }
            }
        }

        cout << res << "\n";
    }

}