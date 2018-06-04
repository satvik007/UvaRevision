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

int n, k, m;
ll dp[60][60];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n >> k >> m) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < k; j++) {
                for(int p = 1; p <= m; p++) {
                    if(i + p <= n)
                        dp[i + p][j + 1] += dp[i][j];
                }
            }
        }
        cout << dp[n][k] << "\n";
    }

}